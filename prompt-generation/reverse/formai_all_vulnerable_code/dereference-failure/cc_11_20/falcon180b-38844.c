//Falcon-180B DATASET v1.0 Category: Networking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[MAXLINE];

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <ip_address>\n", argv[0]);
        exit(1);
    }

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "invalid address/port\n");
        exit(1);
    }

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        clilen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen)) < 0) {
            perror("accept");
            exit(1);
        }

        printf("connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (TRUE) {
            memset(buffer, 0, MAXLINE);
            if (recv(connfd, buffer, MAXLINE, 0) <= 0) {
                if (errno!= EWOULDBLOCK) {
                    perror("recv");
                    exit(1);
                }
                break;
            }

            printf("client message: %s\n", buffer);

            if (send(connfd, buffer, strlen(buffer), 0) < 0) {
                perror("send");
                exit(1);
            }
        }

        close(connfd);
    }

    return 0;
}