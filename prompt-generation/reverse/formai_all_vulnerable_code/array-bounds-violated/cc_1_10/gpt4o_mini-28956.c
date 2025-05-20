//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int read_size;
    
    while ((read_size = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the buffer
        printf("Client: %s", buffer); // Print received message

        // Echo the message back to the client
        send(client_socket, buffer, read_size, 0);
    }

    // Client disconnected
    close(client_socket);
}

int main() {
    int server_socket, client_socket, addr_size;
    struct sockaddr_in server_addr, client_addr;
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d\n", PORT);
    
    addr_size = sizeof(client_addr);
    
    // Accept clients
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addr_size)) >= 0) {
        printf("Client connected\n");
        
        // Create a child process to handle the client
        if (fork() == 0) {
            close(server_socket); // Close the parent's socket in the child
            
            handle_client(client_socket);
            exit(0); // Terminate the child process after handling the client
        }
        
        close(client_socket); // Parent process closes the client socket
    }
    
    if (client_socket < 0) {
        perror("Accept failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    close(server_socket);
    return 0;
}