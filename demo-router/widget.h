#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "serialport.h"
#include "serialreadthread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <QLabel>
#define OP_OK 0
#define OP_ERROR 1
static void process_recv_serialport(int fd)
{

}
/*
void *read_port_thread(void *argc)
{
    int num;
    int fd;

    fd = (int)argc;
    while (1)
    {
        while ((num = read(fd, tmp, 512)) > 0)
        {
            debug_msg("read num: %d\n", num);
            tmp[num + 1] = '\0';
            printf("[%s]\n", tmp);
            process_recv_serialport(fd);
        }

        if (num < 0)
            pthread_exit(NULL);
    }
    pthread_exit(NULL);
}
*/
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();
    void getallserialport();
    serialreadthread* m_preadThread;
    QTimer* m_pTimer;
    static int serial;
    char sendbuf[512];
    char rxbuf[512];
    int online;
    int csq;
    QString strapn;
    int open4gserial();
    void configserial();
    int sendindex;
    int mask;
    QString cops;
    QString band;
    void keyPressEvent(QKeyEvent *event);
public slots:
    void ask_timeout();
    void update4gs(int flag,int ceq,QString cops,QString band);
private:
    Ui::Widget *ui;
};
extern Widget* mwgt;
#endif // WIDGET_H