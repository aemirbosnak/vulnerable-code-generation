//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<errno.h>
#include<sys/time.h>
#include<time.h>
#define TRUE 1
#define FALSE 0
#define MAX 100
#define PORT 8080
#define SA struct sockaddr
int main(int argc, char *argv[])
{
    int listenfd, connfd, addrlen;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX];
    int fd;
    fd_set readfds;
    char *msg;
    int count;
    FD_ZERO(&readfds);
    FD_SET(0,&readfds);
    FD_SET(listenfd,&readfds);
    count=select(FD_SETSIZE,&readfds,NULL,NULL,NULL);
    if(FD_ISSET(0,&readfds))
    {
        fgets(buffer,MAX,stdin);
        msg=buffer;
        send(connfd,msg,strlen(msg),0);
    }
    else if(FD_ISSET(listenfd,&readfds))
    {
        addrlen=sizeof(cliaddr);
        connfd=accept(listenfd,(SA*)&cliaddr,&addrlen);
        FD_SET(connfd,&readfds);
        count++;
    }
    else
    {
        for(fd=0;fd<=FD_SETSIZE-1;fd++)
        {
            if(FD_ISSET(fd,&readfds))
            {
                if(fd==listenfd)
                {
                    addrlen=sizeof(cliaddr);
                    connfd=accept(listenfd,(SA*)&cliaddr,&addrlen);
                    FD_SET(connfd,&readfds);
                    count++;
                }
                else
                {
                    recv(fd,buffer,MAX,0);
                    printf("Client : %s",buffer);
                }
            }
        }
    }
}