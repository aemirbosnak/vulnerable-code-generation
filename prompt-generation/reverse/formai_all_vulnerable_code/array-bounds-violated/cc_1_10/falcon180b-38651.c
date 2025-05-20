//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110
#define USER "your_username"
#define PASS "your_password"
#define SERVER "pop3.example.com"

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(POP3_PORT);
    serveraddr.sin_addr.s_addr = inet_addr(SERVER);

    connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

    printf("Connected to %s:%d\n", SERVER, POP3_PORT);

    send(sockfd, "USER ", 5, 0);
    send(sockfd, USER, strlen(USER), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    send(sockfd, "PASS ", 5, 0);
    send(sockfd, PASS, strlen(PASS), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    send(sockfd, "STAT", 4, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    send(sockfd, "RETR 1", 6, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}