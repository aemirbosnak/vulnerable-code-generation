//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define PORT 21
#define SERVER "localhost"

int main() {
    int sockfd, ret;
    struct sockaddr_in serveraddr;
    char sendbuf[BUFFER_SIZE], recvbuf[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket() failed\n");
        exit(EXIT_FAILURE);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &serveraddr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (ret == -1) {
        printf("Error: connect() failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command (get, put, quit): ");
        scanf("%s", sendbuf);

        if (send(sockfd, sendbuf, strlen(sendbuf), 0) == -1) {
            printf("Error: send() failed\n");
            exit(EXIT_FAILURE);
        }

        n = recv(sockfd, recvbuf, BUFFER_SIZE, 0);
        if (n == -1) {
            printf("Error: recv() failed\n");
            exit(EXIT_FAILURE);
        }

        printf("Server response: %s\n", recvbuf);
    }

    close(sockfd);
    return 0;
}