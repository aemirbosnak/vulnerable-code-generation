//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    
    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate the received data
        printf("Client says: %s", buffer);
        send(client_socket, buffer, bytes_read, 0);  // Echo back the message
    }
    
    if (bytes_read == 0) {
        printf("Client disconnected.\n");
    } else if (bytes_read < 0) {
        perror("recv");
    }
    
    close(client_socket);
    exit(0);  // Terminate child process
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create the network socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Bind to all available interfaces
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening on port %d\n", PORT);
    
    // Accept clients in a loop
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        
        if (client_socket < 0) {
            perror("Accept failed");
            continue;  // Continue accepting other clients
        }
        
        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        
        // Fork a new process to handle the client
        if (fork() == 0) {
            close(server_socket);  // Child process does not need the listening socket
            handle_client(client_socket);
            exit(0);  // Terminate child process after handling client
        }
        
        close(client_socket);  // Parent process closes the connected socket
        // Optionally, you can add waitpid() to clean up zombie processes
    }
    
    close(server_socket);
    return 0;
}