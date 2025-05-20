//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buf[MAX_LINE];
    int n;
    fd_set readfds;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(listenfd, &readfds);

    while (TRUE) {
        FD_ZERO(&readfds);
        FD_SET(listenfd, &readfds);
        n = select(FD_SETSIZE, &readfds, NULL, NULL, NULL);
        if (n == -1) {
            perror("select");
            exit(1);
        }

        if (FD_ISSET(listenfd, &readfds)) {
            connfd = accept(listenfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
            if (connfd == -1) {
                perror("accept");
                exit(1);
            }

            printf("Accepted connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

            FD_SET(connfd, &readfds);
        }

        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &readfds)) {
                if (i == listenfd) {
                    continue;
                }

                n = recv(i, buf, MAX_LINE, 0);
                if (n <= 0) {
                    if (n == 0) {
                        printf("Connection closed by client\n");
                    } else {
                        perror("recv");
                    }

                    close(i);
                    FD_CLR(i, &readfds);
                    continue;
                }

                buf[n] = '\0';
                printf("Received message from %s:%d: %s\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port), buf);

                send(i, buf, n, 0);
            }
        }
    }

    return 0;
}