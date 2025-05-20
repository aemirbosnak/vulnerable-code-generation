//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0
#define PORT 12345
#define BACKLOG 10
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd, ret;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t addrlen;
    char buffer[MAXLINE];

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
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        addrlen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &addrlen);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        printf("client connected, ip: %s, port: %d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        ret = fork();
        if (ret == -1) {
            perror("fork");
            close(connfd);
            continue;
        } else if (ret == 0) {
            close(listenfd);

            while (TRUE) {
                memset(buffer, 0, MAXLINE);
                ret = recv(connfd, buffer, MAXLINE, 0);
                if (ret <= 0) {
                    break;
                }

                printf("client message: %s\n", buffer);

                ret = send(connfd, buffer, strlen(buffer), 0);
                if (ret <= 0) {
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