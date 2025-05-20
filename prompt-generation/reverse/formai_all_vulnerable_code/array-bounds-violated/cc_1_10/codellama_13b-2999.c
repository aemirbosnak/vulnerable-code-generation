//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: retro
/*
 * Socket Programming Example
 *
 * A retro-style C program that demonstrates basic socket programming.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUF 1024

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation error");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding error");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Socket listening error");
        exit(1);
    }

    printf("Server is waiting for connections...\n");

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_sock < 0) {
        perror("Socket acceptance error");
        exit(1);
    }

    printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Receive data from the client
    char buf[MAX_BUF];
    int bytes_recv = recv(client_sock, buf, MAX_BUF, 0);
    if (bytes_recv < 0) {
        perror("Socket receive error");
        exit(1);
    }
    buf[bytes_recv] = '\0';

    printf("Client sent: %s\n", buf);

    // Send data to the client
    char response[] = "Hello, client!";
    int bytes_sent = send(client_sock, response, strlen(response), 0);
    if (bytes_sent < 0) {
        perror("Socket send error");
        exit(1);
    }

    // Close the socket
    close(sock);

    printf("Connection closed\n");

    return 0;
}