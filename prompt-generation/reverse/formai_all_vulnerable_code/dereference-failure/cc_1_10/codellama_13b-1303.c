//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: expert-level
/*
 * TCP/IP Programming Example
 *
 * This program demonstrates a simple TCP/IP client and server
 * program using the BSD Sockets API. The client connects to
 * the server and sends a message, while the server receives
 * the message and sends a response.
 *
 * Usage:
 *   server:
 *     ./tcp_ip_server <port>
 *   client:
 *     ./tcp_ip_client <address> <port>
 *
 *   where <port> is the port number to listen on, and <address>
 *   is the IP address of the server.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    // Check arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <address> <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Set up address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton() failed");
        return 1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        return 1;
    }

    // Send message
    char message[] = "Hello, server!";
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send() failed");
        return 1;
    }

    // Receive response
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv() failed");
        return 1;
    }

    // Print response
    printf("Received response: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}