//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXLINE];
    socklen_t clilen;
    pid_t pid;

    if (argc < 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    if (listenfd == -1) {
        perror("socket failed");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen failed");
        exit(1);
    }

    while (TRUE) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);

        if (connfd == -1) {
            perror("accept failed");
            exit(1);
        }

        pid = fork();

        if (pid == -1) {
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            close(listenfd);

            while (TRUE) {
                memset(buffer, 0, MAXLINE);
                if (recv(connfd, buffer, MAXLINE, 0) <= 0) {
                    break;
                }

                if (send(connfd, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                    break;
                }
            }

            close(connfd);
            exit(0);
        } else {
            close(connfd);
        }
    }

    return 0;
}