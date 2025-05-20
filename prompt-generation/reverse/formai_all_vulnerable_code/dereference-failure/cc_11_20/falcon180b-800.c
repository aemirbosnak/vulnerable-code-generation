//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 10
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[MAXLINE];

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(12345);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port 12345...\n");

    while (TRUE) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (TRUE) {
            memset(buffer, 0, MAXLINE);
            if (recv(connfd, buffer, MAXLINE, 0) <= 0) {
                if (errno == ECONNRESET) {
                    printf("Connection reset by peer.\n");
                } else if (errno!= EAGAIN) {
                    perror("recv");
                }
                break;
            }

            printf("Received message: %s", buffer);

            if (send(connfd, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                perror("send");
                break;
            }
        }

        close(connfd);
    }

    close(listenfd);
    return 0;
}