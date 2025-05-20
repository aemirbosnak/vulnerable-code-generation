//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAXBUF 4096
#define SERVER_PORT 8080

int main(int argc, char **argv)
{
    int listenfd, connfd, n, targetfd;
    struct sockaddr_in listenaddr, targetaddr;
    char buf[MAXBUF];

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&listenaddr, 0, sizeof(listenaddr));
    listenaddr.sin_family = AF_INET;
    listenaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    listenaddr.sin_port = htons(SERVER_PORT);

    if (bind(listenfd, (struct sockaddr*) &listenaddr, sizeof(listenaddr))) {
        printf("Failed to bind: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listenfd, 10) < 0) {
        printf("Failed to listen: %s\n", strerror(errno));
        exit(1);
    }

    printf("Listening on port %d...\n", SERVER_PORT);

    while (1) {
        if ((connfd = accept(listenfd, (struct sockaddr*) NULL, NULL)) < 0) {
            printf("Failed to accept connection: %s\n", strerror(errno));
            continue;
        }

        if (fork() == 0) {
            close(listenfd);

            if ((n = recv(connfd, buf, MAXBUF, 0)) < 0) {
                printf("Failed to receive data: %s\n", strerror(errno));
                exit(1);
            }

            buf[n] = '\0';
            printf("Received request:\n%s\n", buf);

            memset(&targetaddr, 0, sizeof(targetaddr));
            targetaddr.sin_family = AF_INET;
            targetaddr.sin_port = htons(80);

            if (inet_pton(AF_INET, "127.0.0.1", &targetaddr.sin_addr) <= 0) {
                printf("Failed to parse target IP address: %s\n", strerror(errno));
                exit(1);
            }

            if ((targetfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                printf("Failed to create socket: %s\n", strerror(errno));
                exit(1);
            }

            if (connect(targetfd, (struct sockaddr*) &targetaddr, sizeof(targetaddr)) < 0) {
                printf("Failed to connect to target: %s\n", strerror(errno));
                exit(1);
            }

            if (send(targetfd, buf, n, 0) < 0) {
                printf("Failed to send data to target: %s\n", strerror(errno));
                exit(1);
            }

            while (1) {
                if ((n = recv(targetfd, buf, MAXBUF, 0)) < 0) {
                    printf("Failed to receive data from target: %s\n", strerror(errno));
                    exit(1);
                } else if (n == 0) {
                    break;
                }

                if (send(connfd, buf, n, 0) < 0) {
                    printf("Failed to send data to client: %s\n", strerror(errno));
                    exit(1);
                }
            }

            close(connfd);
            close(targetfd);
            exit(0);
        }

        close(connfd);
    }

    return 0;
}