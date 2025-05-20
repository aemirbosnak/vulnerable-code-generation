//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAXLINE 4096

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, clientaddr;
    socklen_t addrlen;
    char buffer[MAXLINE];
    int new_socket;
    int opt = 1;
    int addrlen_client;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (TRUE) {
        addrlen = sizeof(clientaddr);
        if ((new_socket = accept(listenfd, (struct sockaddr *)&clientaddr, &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

        while (TRUE) {
            memset(buffer, 0, sizeof(buffer));
            if (recv(new_socket, buffer, MAXLINE, 0) <= 0) {
                if (errno!= EWOULDBLOCK) {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }
                break;
            }
            printf("Received message: %s\n", buffer);

            if (send(new_socket, buffer, strlen(buffer), 0) < 0) {
                perror("send");
                exit(EXIT_FAILURE);
            }
        }

        close(new_socket);
    }

    close(listenfd);
    return 0;
}