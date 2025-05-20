//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[read_size] = '\0'; // Null terminate the string
        printf("Received from client: %s\n", buffer);

        // Echo back the same message
        send(client_socket, buffer, read_size, 0);
    }

    if (read_size == -1) {
        error_handling("recv failed");
    }

    printf("Client disconnected.\n");
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error_handling("Socket failed");
    }

    // Set up server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY; // Bind to any available interface
    server_address.sin_port = htons(PORT);

    // Bind the socket to the desired port
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        error_handling("Bind failed");
    }

    // Start listening for incoming connections
    if (listen(server_socket, 3) < 0) {
        error_handling("Listen failed");
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept incoming connections in an infinite loop
    while (1) {
        // Accept a new client connection
        if ((client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len)) < 0) {
            error_handling("Accept failed");
        }

        printf("New client connected.\n");

        // Handle the client in a separate function
        handle_client(client_socket);
    }

    // Close the server socket (unreachable code in this loop)
    close(server_socket);
    return 0;
}