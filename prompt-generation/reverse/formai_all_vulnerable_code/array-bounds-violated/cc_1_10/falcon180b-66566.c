//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 1024
#define PORT 8080
#define SA struct sockaddr

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    int opt = 1;
    int addrlen = sizeof(cliaddr);

    if (argc < 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        error("socket failed");
    }

    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (SA *)&servaddr, sizeof(servaddr)) < 0) {
        error("bind failed");
    }

    if (listen(listenfd, 5) < 0) {
        error("listen");
    }

    while (1) {
        connfd = accept(listenfd, (SA *)&cliaddr, &addrlen);
        if (connfd < 0) {
            error("accept");
        }

        printf("Connection from: %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        char buffer[MAX];
        while (1) {
            bzero(buffer, MAX);
            int bytes_received = recv(connfd, buffer, MAX, 0);

            if (bytes_received <= 0) {
                if (bytes_received == 0) {
                    printf("Client disconnected\n");
                } else {
                    error("recv");
                }
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            if (send(connfd, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                error("send");
            }
        }

        close(connfd);
    }

    return 0;
}