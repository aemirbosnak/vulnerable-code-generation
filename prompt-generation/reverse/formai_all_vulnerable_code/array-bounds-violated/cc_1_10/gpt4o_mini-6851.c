//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 5
#define BUFFER_SIZE 1024

// Function to handle communication with the client
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("Received: %s", buffer); // Print the received message

        // Echoing back the message to client
        send(client_socket, buffer, bytes_received, 0);
        printf("Echoed back to client: %s", buffer);
    }

    if (bytes_received < 0) {
        perror("recv failed");
    }

    close(client_socket); // Close the socket when done
    printf("Client disconnected\n");
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Zero out the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to any available interface
    server_addr.sin_port = htons(PORT); // Convert port to network byte order

    // Binding the socket to the port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, BACKLOG) == -1) {
        perror("listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);

    // Accepting clients in a loop
    while (1) {
        // Accept a new connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) == -1) {
            perror("accept failed");
            continue; // Continue to accept the next connection
        }

        printf("Client connected from IP: %s, Port: %d\n",
               inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        
        // Handle the client in a concurrent/session model
        if (fork() == 0) {
            // Child process: handle client and exit when done
            close(server_socket); // Child does not need the server socket
            handle_client(client_socket);
            exit(0);
        }

        // Parent process closes the client socket, continues to listen for next connection
        close(client_socket);
    }

    // Clean up (although this point will never be reached in an infinite loop)
    close(server_socket);
    return 0;
}