//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendbuf[BUF_SIZE], recvbuf[BUF_SIZE];
    char user[64], pass[64];
    int port = 110; // POP3 port

    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", pass);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, "localhost", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    char *auth = "USER ";
    strcat(auth, user);
    strcat(auth, "\r\n");
    send(sockfd, auth, strlen(auth), 0);

    char *pass_auth = "PASS ";
    strcat(pass_auth, pass);
    strcat(pass_auth, "\r\n");
    send(sockfd, pass_auth, strlen(pass_auth), 0);

    char *stat = "STAT\r\n";
    send(sockfd, stat, strlen(stat), 0);

    while ((n = recv(sockfd, recvbuf, BUF_SIZE, 0)) > 0) {
        recvbuf[n] = '\0';
        printf("%s", recvbuf);
    }

    close(sockfd);
    return 0;
}