//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main() {
    int sockfd;
    char buffer[MAX_BUF_SIZE];
    struct sockaddr_in serverAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(21);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) != 0) {
        printf("Error: Failed to connect.\n");
        exit(EXIT_FAILURE);
    }

    printf("Successfully connected to FTP server at 127.0.0.1:21.\n");

    // Login
    printf("Enter username and password to login. (Note: Only anonymous login is supported in this example.)\n");

    // Username
    printf("Username: ");
    scanf("%s", buffer);
    sprintf(buffer, "%s\r\n", buffer);
    send(sockfd, buffer, strlen(buffer), 0);

    // Password
    printf("Password: ");
    scanf("%s", buffer);
    sprintf(buffer, "%s\r\n", buffer);
    send(sockfd, buffer, strlen(buffer), 0);

    // Check response
    recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    printf("%s", buffer);

    // List directory
    printf("Enter a command. (Note: Only 'ls' is supported in this example.)\n");
    scanf("%s", buffer);
    sprintf(buffer, "%s\r\n", buffer);
    send(sockfd, buffer, strlen(buffer), 0);

    // Get response
    while (recv(sockfd, buffer, MAX_BUF_SIZE, 0) > 0) {
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}