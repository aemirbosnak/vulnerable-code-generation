//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024
#define LISTENQ 10
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in listenaddr, clientaddr;
    socklen_t clientlen;
    char *http_methods[] = {"GET", "POST", "HEAD", "PUT", "DELETE", "CONNECT", "OPTIONS", "TRACE"};
    char buffer[MAXLINE];
    int i, n;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&listenaddr, 0, sizeof(listenaddr));
    listenaddr.sin_family = AF_INET;
    listenaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    listenaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&listenaddr, sizeof(listenaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, LISTENQ) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Proxy server started on port %d\n", atoi(argv[1]));

    while (TRUE) {
        clientlen = sizeof(clientaddr);
        connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

        for (i = 0; i < sizeof(http_methods) / sizeof(http_methods[0]); i++) {
            n = send(connfd, http_methods[i], strlen(http_methods[i]), 0);
            if (n == -1) {
                perror("send");
                break;
            }
        }

        while (TRUE) {
            n = recv(connfd, buffer, MAXLINE, 0);
            if (n == -1) {
                perror("recv");
                break;
            }

            if (n == 0) {
                break;
            }

            printf("Received %d bytes: %s", n, buffer);
        }

        close(connfd);
    }

    return 0;
}