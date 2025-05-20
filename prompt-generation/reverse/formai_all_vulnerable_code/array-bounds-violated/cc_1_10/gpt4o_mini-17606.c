//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int msg_count = 0;
    ssize_t bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the received string
        msg_count++;

        printf("Received message #%d: %s\n", msg_count, buffer);

        // Echoing the received message back to the client
        if (send(client_socket, buffer, bytes_received, 0) == -1) {
            perror("send failed");
            break;
        }
    }

    if (bytes_received == -1) {
        perror("recv failed");
    }

    printf("Client disconnected. Total messages received: %d\n", msg_count);
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Creating the socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    // Preparing the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to any available interface
    server_addr.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listening for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listening failed");
        close(server_socket);
        return EXIT_FAILURE;
    }
    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accepting incoming client connections
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle client communication
        handle_client(client_socket);
    }

    // Cleanup (this code will not be reached in the current infinite loop)
    close(server_socket);
    return EXIT_SUCCESS;
}