//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char buffer[BUFFER_SIZE];
    int n;
    int port = 110;

    printf("POP3 Client\n");
    printf("Enter username: ");
    fgets(username, 50, stdin);
    printf("Enter password: ");
    fgets(password, 50, stdin);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    send(sockfd, "USER ", 5, 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    send(sockfd, "PASS ", 5, 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    send(sockfd, "STAT\r\n", 6, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    send(sockfd, "RETR 1\r\n", 8, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("Message: %s", buffer);
    }

    close(sockfd);

    return 0;
}