//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    int n;

    // Initialize the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send a message to the server
    strcpy(buffer, "Hello, server!");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending message\n");
        exit(1);
    }

    // Receive a message from the server
    if ((n = recv(sockfd, buffer, BUF_SIZE, 0)) == -1) {
        printf("Error receiving message\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Message from server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}