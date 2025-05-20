//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: thoughtful
/*
 * A unique C TCP/IP programming example program in a thoughtful style.
 * This program is designed to demonstrate the use of TCP/IP sockets for
 * sending and receiving data over a network.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    // Check if the command line arguments are valid
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create a new TCP/IP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket()");
        return 1;
    }

    // Set up the address structure for the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect()");
        return 1;
    }

    // Send a message to the server
    char *message = "Hello, server!";
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send()");
        return 1;
    }

    // Receive a message from the server
    char buffer[1024];
    int n = recv(sock, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv()");
        return 1;
    }
    buffer[n] = '\0';
    printf("Received message: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}