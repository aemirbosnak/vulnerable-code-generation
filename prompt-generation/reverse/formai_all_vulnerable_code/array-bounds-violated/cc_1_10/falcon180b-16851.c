//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 25
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char *serverip = "smtp.gmail.com";
    char *username = "your_username";
    char *password = "your_password";
    char buffer[MAXLINE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    inet_pton(AF_INET, serverip, &serveraddr.sin_addr);
    serveraddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, "EHLO smtp.gmail.com\r\n", strlen("EHLO smtp.gmail.com\r\n"), 0);

    while ((n = recv(sockfd, buffer, MAXLINE, 0)) > 0) {
        buffer[n] = '\0';
        printf("Received: %s", buffer);
    }

    close(sockfd);

    return 0;
}