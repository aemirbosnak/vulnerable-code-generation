//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER "localhost"
#define PORT 110
#define USER "username"
#define PASS "password"
#define BUF_SIZE 1024


int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char sendbuf[BUF_SIZE];
    char recvbuf[BUF_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%d\n", SERVER, PORT);

    char *cmd = "USER ";
    strcat(cmd, USER);
    strcat(cmd, "\r\n");
    send(sockfd, cmd, strlen(cmd), 0);

    char *pwd = "PASS ";
    strcat(pwd, PASS);
    strcat(pwd, "\r\n");
    send(sockfd, pwd, strlen(pwd), 0);

    char *stat = "STAT\r\n";
    send(sockfd, stat, strlen(stat), 0);

    while (1) {
        memset(recvbuf, 0, BUF_SIZE);
        n = recv(sockfd, recvbuf, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Disconnected\n");
            break;
        }
        printf("%s", recvbuf);
    }

    close(sockfd);
    return 0;
}