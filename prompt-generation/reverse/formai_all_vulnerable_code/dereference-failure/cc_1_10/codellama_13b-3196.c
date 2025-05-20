//Code Llama-13B DATASET v1.0 Category: Client Server Application ; Style: all-encompassing
/*
 * Client-Server Application Example
 *
 * This program demonstrates a simple client-server application using the TCP/IP protocol.
 * The client sends a message to the server, and the server responds with a message.
 *
 * Compile with: gcc -o client_server client_server.c
 *
 * Usage: ./client_server <server_ip> <server_port> <message>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port> <message>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid server IP address\n");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the message to the server
    char buffer[BUFFER_SIZE];
    strcpy(buffer, argv[3]);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print the response
    printf("Response from server: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}