//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define MAXLINE 1024
#define PORT 21
#define SERVER "127.0.0.1"

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char username[MAXLINE];
    char password[MAXLINE];
    char buffer[MAXLINE];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    while (1) {
        memset(buffer, 0, MAXLINE);
        if (recv(sockfd, buffer, MAXLINE, 0) <= 0) {
            perror("recv failed");
            exit(1);
        }
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}