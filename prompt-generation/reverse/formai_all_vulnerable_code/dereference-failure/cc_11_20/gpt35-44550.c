//FormAI DATASET v1.0 Category: Socket programming ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if the required arguments are provided
    if (argc != 3) {
        printf("Usage: %s <server-ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton() failed");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // Read input from user and send to server
    char buffer[BUFFER_SIZE];
    while (1) {
        printf("Enter a message (type 'exit' to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Remove the trailing newline character and add null terminator
        buffer[strcspn(buffer, "\n")] = 0;

        // If the user wants to quit, send a message to the server
        if (strcmp(buffer, "exit") == 0) {
            if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
                perror("send() failed");
                exit(EXIT_FAILURE);
            }
            break;
        }

        // Send the user input to the server
        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("send() failed");
            exit(EXIT_FAILURE);
        }

        // Receive a message from the server
        ssize_t num_bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (num_bytes == -1) {
            perror("recv() failed");
            exit(EXIT_FAILURE);
        }

        // Add null terminator to the received message and print it
        buffer[num_bytes] = 0;
        printf("Received message: %s\n", buffer);
    }

    // Close the socket
    if (close(sockfd) == -1) {
        perror("close() failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}