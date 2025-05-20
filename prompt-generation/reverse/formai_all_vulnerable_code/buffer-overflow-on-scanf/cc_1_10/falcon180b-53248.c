//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

void main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return;
    }

    // Initialize server address
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error connecting to server\n");
        return;
    }

    // Send username
    char username[20];
    printf("Enter username: ");
    scanf("%s", username);
    send(sockfd, username, strlen(username), 0);

    // Send password
    char password[20];
    printf("Enter password: ");
    scanf("%s", password);
    send(sockfd, password, strlen(password), 0);

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error receiving response\n");
        return;
    }
    printf("Response: %s\n", buffer);

    // Close socket
    close(sockfd);
}