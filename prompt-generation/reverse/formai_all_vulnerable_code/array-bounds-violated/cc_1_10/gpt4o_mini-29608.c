//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Loop to continuously receive messages from the client until they disconnect
    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null terminate the buffer
        printf("Client: %s\n", buffer);

        // Echo the message back to the client
        if (send(client_socket, buffer, bytes_read, 0) < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read < 0) {
        perror("recv");
    }

    // Close the client socket when done
    close(client_socket);
    printf("Client disconnected.\n");
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Initialize the server structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // Server loop to accept clients
    while (1) {
        // Accept a new client
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue; // Skip to the next iteration
        }

        printf("New client connected.\n");

        // Handle client in a separate process
        if (fork() == 0) {
            // This is the child process
            close(server_socket); // Close the listening socket in the child
            handle_client(client_socket);
            exit(0);
        } else {
            // Parent process
            close(client_socket); // Close the connected socket in the parent
        }
    }

    // Clean up and close the server socket (unreachable in this loop)
    close(server_socket);
    return 0;
}