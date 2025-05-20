//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define BUFF_SIZE 1024
#define PORT 21
#define TIMEOUT 10

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *host = "ftp.example.com";
    char *username = "username";
    char *password = "password";
    char *command = "LIST";
    char buffer[BUFF_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to FTP server.\n");

    if (login(sockfd, username, password) == -1) {
        perror("login failed");
        exit(EXIT_FAILURE);
    }

    printf("Logged in as %s.\n", username);

    send(sockfd, command, strlen(command), 0);

    while ((n = recv(sockfd, buffer, BUFF_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}