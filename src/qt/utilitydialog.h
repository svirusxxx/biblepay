// Copyright (c) 2011-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_UTILITYDIALOG_H
#define BITCOIN_QT_UTILITYDIALOG_H

#include <QDialog>
#include <QObject>
#include <QNetworkReply>
#include "wallet/crypter.h"

class BitcoinGUI;
class ClientModel;

namespace Ui 
{
    class HelpMessageDialog;
}

/** "Help message" dialog box */
class HelpMessageDialog : public QDialog
{
    Q_OBJECT

public:
    enum HelpMode 
	{
        about,
        cmdline,
        pshelp,
		prayer,
		readbible,
		createnews,
		readnews,
		previewnews
    };

    explicit HelpMessageDialog(QWidget *parent, HelpMode helpMode, int iPrayer, uint256 txid, std::string sPreview);
    ~HelpMessageDialog();
	
    void printToConsole();
    void showOrPrint();

private:
    Ui::HelpMessageDialog *ui;
    QString text;

private Q_SLOTS:
    void on_okButton_accepted();
	void on_btnPublishClicked();
	void on_btnPreviewClicked();
	void on_comboBookClicked(int iClick);
	void on_comboChapterClicked(int iClick);
	

};


/** "Shutdown" window */
class ShutdownWindow : public QWidget
{
    Q_OBJECT

public:
    ShutdownWindow(QWidget *parent=0, Qt::WindowFlags f=0);
    static void showShutdownWindow(BitcoinGUI *window);

protected:
    void closeEvent(QCloseEvent *event);
};


/** News Preview window */
class NewsPreviewWindow : public QWidget
{
	Q_OBJECT
public:
	NewsPreviewWindow(QWidget *parent=0, Qt::WindowFlags f=0);
	static void showNewsPreviewWindow(QWidget *myparent);
	static void showNewsWindow(QWidget *myparent, std::string sTXID);

private Q_SLOTS:
	void downloadFinished(QNetworkReply *reply);
	bool DownloadImage(std::string sURL);
	QString ReplaceImageTags(QString qsp);

protected:
	void closeEvent(QCloseEvent *event);

};

#endif // BITCOIN_QT_UTILITYDIALOG_H
