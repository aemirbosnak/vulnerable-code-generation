//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <signal.h>

// Handle Ctrl+C and clean up
void sigint_handler(int sig) {
    printf("\nShutting down server gracefully...\n");
    exit(0);
}

int main() {
    // Register Ctrl+C handler
    signal(SIGINT, sigint_handler);

    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        return -1;
    }

    // Bind the socket to an address and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(9999);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Failed to listen");
        return -1;
    }

    printf("Server listening on port 9999...\n");

    // Accept incoming connections and handle them
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);

        // Accept a connection
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue;
        }

        // Create a thread to handle the client
        int pid = fork();
        if (pid == 0) {  // Child process
            close(server_socket);

            char buffer[1024];
            int n;

            // Receive a message from the client
            n = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
            if (n < 0) {
                perror("Failed to receive message");
                close(client_socket);
                exit(0);
            }

            // Null-terminate the message
            buffer[n] = '\0';

            // Process the message
            printf("Received message from client: %s\n", buffer);

            // Send a response to the client
            n = send(client_socket, "Hello, world!", 13, 0);
            if (n < 0) {
                perror("Failed to send message");
                close(client_socket);
                exit(0);
            }

            // Close the client socket
            close(client_socket);
            exit(0);
        } else if (pid > 0) {  // Parent process
            close(client_socket);
        } else {  // Error
            perror("Failed to fork");
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}