//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    int opt = 1;
    int addrlen = sizeof(cliaddr);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while (TRUE) {
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &addrlen);
        if (connfd == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection from: %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        char buffer[1024];
        int bytes_received = 0;
        while ((bytes_received = recv(connfd, buffer, sizeof(buffer), 0)) > 0) {
            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            if (send(connfd, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                exit(1);
            }
        }

        if (bytes_received == 0) {
            printf("Connection closed by client\n");
        } else {
            printf("Connection closed due to error\n");
        }

        close(connfd);
    }

    return 0;
}