//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 4096
#define TRUE 1
#define FALSE 0

int main(int argc, char **argv) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[MAXLINE];
    pid_t childpid;

    if(argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd == -1) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[1]));
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if(listen(listenfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while(TRUE) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
        if(connfd == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection from: %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        childpid = fork();
        if(childpid == -1) {
            perror("fork");
            exit(1);
        }

        if(childpid == 0) {
            close(listenfd);

            while(TRUE) {
                bzero(buffer, MAXLINE);
                if(recv(connfd, buffer, MAXLINE, 0) <= 0) {
                    if(errno!= EWOULDBLOCK) {
                        perror("recv");
                        exit(1);
                    } else {
                        break;
                    }
                }

                send(connfd, buffer, strlen(buffer), 0);
            }

            close(connfd);
            exit(0);
        }

        close(connfd);
    }

    return 0;
}