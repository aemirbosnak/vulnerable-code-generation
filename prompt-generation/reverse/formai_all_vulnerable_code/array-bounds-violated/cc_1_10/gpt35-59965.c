//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9999
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int msg_len, bytes_sent, bytes_received;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    strcpy(buffer, "Hello, server!");
    msg_len = strlen(buffer);
    bytes_sent = send(sockfd, buffer, msg_len, 0);
    if (bytes_sent < 0) {
        perror("Failed to send message");
        exit(EXIT_FAILURE);
    }
    printf("Sent message: %s\n", buffer);

    // Receive a message from the server
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Failed to receive message");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    printf("Received message: %s\n", buffer);

    close(sockfd);
    return 0;
}