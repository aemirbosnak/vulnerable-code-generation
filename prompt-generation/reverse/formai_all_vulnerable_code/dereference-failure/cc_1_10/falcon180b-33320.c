//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BACKLOG 10
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    int port = 8080;
    struct sockaddr_in servaddr;
    char *ip = "127.0.0.1";

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(port);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", port);

    while (1) {
        socklen_t addrlen;
        char buffer[BUFSIZE];
        int newsockfd;
        struct sockaddr_in cliaddr;

        addrlen = sizeof(cliaddr);
        newsockfd = accept(listenfd, (struct sockaddr *)&cliaddr, &addrlen);
        if (newsockfd == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (1) {
            bzero(buffer, BUFSIZE);
            ssize_t bytes_read = read(newsockfd, buffer, BUFSIZE);
            if (bytes_read <= 0) {
                break;
            }

            printf("Received %zd bytes: %s\n", bytes_read, buffer);

            send(newsockfd, buffer, bytes_read, 0);
        }

        close(newsockfd);
    }

    return 0;
}