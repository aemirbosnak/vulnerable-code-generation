//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: expert-level
/*
 * TCP/IP Programming Example
 *
 * This program demonstrates a simple TCP/IP client and server
 * application using the Berkeley sockets API.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function prototypes
void error(const char *msg);

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <address> <port>\n", argv[0]);
        exit(1);
    }

    // Set up the server address and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        error("inet_pton() failed");
    }

    // Create the socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("socket() failed");
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("connect() failed");
    }

    // Send a message to the server
    char message[100] = "Hello, world!";
    if (send(sock, message, strlen(message), 0) < 0) {
        error("send() failed");
    }

    // Receive a message from the server
    char buffer[100];
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        error("recv() failed");
    }
    printf("Received message: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}

// Function definitions
void error(const char *msg) {
    perror(msg);
    exit(1);
}