//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *username = "user";
    char *password = "pass";
    char buffer[BUF_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    if (send(sockfd, username, strlen(username), 0) < 0) {
        printf("Error sending username\n");
        exit(1);
    }

    if (send(sockfd, password, strlen(password), 0) < 0) {
        printf("Error sending password\n");
        exit(1);
    }

    printf("Logged in\n");

    while (1) {
        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            break;
        }

        buffer[n] = '\0';
        printf("Received: %s", buffer);
    }

    close(sockfd);
    return 0;
}