//FormAI DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888
#define BUFFER_SIZE 1024

int main(void) {
    int sockfd;
    struct sockaddr_in client_addr;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    ssize_t bytes_sent, bytes_received;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Set socket information
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    client_addr.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&client_addr, sizeof(client_addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    printf("Enter a message: ");
    fgets(message, BUFFER_SIZE, stdin);
    bytes_sent = send(sockfd, message, strlen(message), 0);
    if (bytes_sent < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }
    printf("Message sent\n");

    // Receive a message from the server
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("Received: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}