//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char recvbuf[BUF_SIZE];
    char sendbuf[BUF_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    strcpy(sendbuf, "USER ");
    strcat(sendbuf, argv[2]);
    strcat(sendbuf, "\r\n");

    strcpy(sendbuf, "PASS ");
    strcat(sendbuf, argv[3]);
    strcat(sendbuf, "\r\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket() failed: %s\n", strerror(errno));
        return 1;
    }

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(110);
    if (inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) <= 0) {
        printf("Error: inet_pton() failed\n");
        close(sockfd);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error: connect() failed: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    if (send(sockfd, sendbuf, strlen(sendbuf), 0) == -1) {
        printf("Error: send() failed: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    while (1) {
        bzero(recvbuf, BUF_SIZE);
        n = recv(sockfd, recvbuf, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Error: recv() failed: %s\n", strerror(errno));
            close(sockfd);
            return 1;
        }

        printf("%s", recvbuf);
    }

    close(sockfd);
    return 0;
}