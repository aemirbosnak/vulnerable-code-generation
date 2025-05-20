//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: accurate
/*
 * chat_server.c - A simple chat server using TCP sockets
 *
 * Usage: ./chat_server <port>
 *
 * Note: This program uses non-blocking I/O, so the server
 * will not block if a client is not connected.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
    int sock, client, bytes_read, bytes_sent;
    struct sockaddr_in server, client_addr;
    char buffer[BUF_SIZE];
    socklen_t client_len = sizeof(client_addr);

    // Check if port is specified
    if (argc < 2) {
        printf("Usage: ./chat_server <port>\n");
        return 1;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Setup server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind and listen
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error binding socket");
        return 1;
    }
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("Error listening on socket");
        return 1;
    }

    // Accept clients
    while (1) {
        client = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client < 0) {
            perror("Error accepting client");
            continue;
        }

        printf("Client connected from %s\n", inet_ntoa(client_addr.sin_addr));

        // Read from client
        while (1) {
            bytes_read = recv(client, buffer, BUF_SIZE, 0);
            if (bytes_read < 0) {
                perror("Error reading from client");
                break;
            } else if (bytes_read == 0) {
                printf("Client disconnected\n");
                break;
            }

            // Echo back to client
            bytes_sent = send(client, buffer, bytes_read, 0);
            if (bytes_sent < 0) {
                perror("Error sending to client");
                break;
            }
        }

        close(client);
    }

    close(sock);
    return 0;
}