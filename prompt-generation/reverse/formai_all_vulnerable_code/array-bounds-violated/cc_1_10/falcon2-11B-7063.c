//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to a port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding to socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    // Accept a new connection
    int client_socket;
    if ((client_socket = accept(server_socket, NULL, NULL)) < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    // Read data from the client
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes_read < 0) {
            perror("Error reading from socket");
            exit(EXIT_FAILURE);
        }
        buffer[bytes_read] = '\0';
        printf("Received message: %s\n", buffer);

        // Send a response back to the client
        send(client_socket, "Message received!", sizeof("Message received!") - 1, 0);
    }

    return 0;
}