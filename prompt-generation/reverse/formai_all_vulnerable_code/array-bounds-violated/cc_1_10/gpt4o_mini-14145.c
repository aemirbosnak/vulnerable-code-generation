//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null terminate the received data
        printf("Client: %s\n", buffer);
        
        // Echos back to client
        send(client_socket, buffer, bytes_read, 0);
    }

    if (bytes_read < 0) {
        perror("recv failed");
    }

    close(client_socket);
    printf("Client disconnected.\n");
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP address
    server_addr.sin_port = htons(PORT); // Convert to big-endian

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue; // Skip to the next loop iteration
        }

        printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

        // Fork a new process to handle the client
        if (fork() == 0) {
            // Child process
            close(server_socket); // Close the server socket in the child process
            handle_client(client_socket);
            exit(0); // Ensure the child process terminates after handling the client
        }

        // Parent process
        close(client_socket); // Parent does not need to use this socket
    }

    close(server_socket);
    return 0;
}