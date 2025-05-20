//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAXLINE 1024
#define TRUE 1
#define FALSE 0
#define PORT 8080
#define SA struct sockaddr

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[MAXLINE];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (SA *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (SA *)&cliaddr, &clilen);
        if (connfd == -1) {
            perror("accept");
            exit(1);
        }

        printf("client connected: %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (TRUE) {
            n = recv(connfd, buffer, MAXLINE, 0);
            if (n == 0) {
                break;
            }

            if (n == -1) {
                perror("recv");
                exit(1);
            }

            buffer[n] = '\0';

            printf("received: %s\n", buffer);

            send(connfd, buffer, n, 0);
        }

        close(connfd);
    }

    return 0;
}