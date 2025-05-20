//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char sendbuf[BUF_SIZE];
    char recvbuf[BUF_SIZE];
    int n;
    int port = 143; // IMAP port

    if (argc!= 4) {
        printf("Usage:./client <host> <username> <password>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to host: %s\n", argv[1]);

    sprintf(sendbuf, "A001 LOGIN %s %s\r\n", argv[2], argv[3]);
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    while (1) {
        memset(recvbuf, '0', BUF_SIZE);
        n = recv(sockfd, recvbuf, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Disconnected\n");
            break;
        }
        recvbuf[n] = '\0';
        printf("Received: %s", recvbuf);
    }

    close(sockfd);
    return 0;
}