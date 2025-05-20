//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        printf("Client sent: %s", buffer);
        
        // Echo back the message to the client
        send(client_socket, buffer, bytes_read, 0);
        memset(buffer, 0, BUFFER_SIZE); // Clear buffer
    }

    if (bytes_read == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("recv");
    }
    
    close(client_socket);
    exit(0); // Terminate the child process when done
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server listening on port %d...\n", PORT);

    while (1) {
        // Accept a new connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("Accept failed");
            continue; // Continue to next iteration for a new connection
        }

        printf("New client connected!\n");

        // Fork to handle the client in a new process
        if (fork() == 0) {
            // We are in the child process
            close(server_socket); // Close the listening socket in child
            handle_client(client_socket);
            exit(0);
        }

        close(client_socket); // Parent process closes the client socket
        wait(NULL); // Prevent zombie processes
    }

    // Clean up
    close(server_socket);
    return 0;
}