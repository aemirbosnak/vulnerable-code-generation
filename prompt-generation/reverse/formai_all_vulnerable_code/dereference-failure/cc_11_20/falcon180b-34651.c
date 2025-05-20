//Falcon-180B DATASET v1.0 Category: Networking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
        if (connfd == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s on port %d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (TRUE) {
            bzero(buffer, sizeof(buffer));
            if (recv(connfd, buffer, sizeof(buffer), 0) <= 0) {
                if (errno!= EAGAIN) {
                    perror("recv");
                }
                break;
            }

            printf("Received message: %s", buffer);

            if (send(connfd, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                perror("send");
            }
        }

        close(connfd);
    }

    close(listenfd);
    return 0;
}