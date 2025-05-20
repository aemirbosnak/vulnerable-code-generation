//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char *ip = "127.0.0.1";
    int port = PORT;
    char buffer[MAXLINE];
    time_t now;
    char *date = ctime(&now);

    printf("Server started on %s\n", date);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(port);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        connfd = accept(listenfd, NULL, NULL);
        if (connfd == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        bzero(buffer, MAXLINE);
        send(connfd, "Server started at ", strlen("Server started at "), 0);
        send(connfd, date, strlen(date), 0);
        send(connfd, "\n", 1, 0);

        while (1) {
            bzero(buffer, MAXLINE);
            int bytes_received = recv(connfd, buffer, MAXLINE, 0);
            if (bytes_received <= 0) {
                printf("Connection closed by client\n");
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Client message: %s\n", buffer);

            time_t now;
            char *date = ctime(&now);

            send(connfd, "Server received message at ", strlen("Server received message at "), 0);
            send(connfd, date, strlen(date), 0);
            send(connfd, "\n", 1, 0);
        }

        close(connfd);
    }

    return 0;
}