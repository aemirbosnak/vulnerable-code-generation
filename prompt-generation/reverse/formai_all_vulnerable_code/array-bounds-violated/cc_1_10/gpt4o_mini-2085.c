//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *client_socket);
void error_handling(const char *message);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    
    // Creating a TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error_handling("socket() error");
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP
    server_addr.sin_port = htons(PORT); // Convert to network byte order

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        close(server_socket);
        error_handling("bind() error");
    }
    
    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        close(server_socket);
        error_handling("listen() error");
    }
    
    printf("Server is listening on port %d...\n", PORT);
    
    while (1) {
        // Accept a client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            perror("accept() error");
            continue; // Skip to the next iteration on error
        }

        printf("Connected to client: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        
        // Create a thread for each client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)(intptr_t)client_socket) != 0) {
            perror("pthread_create() error");
            close(client_socket); // Clean up
        }
        
        pthread_detach(tid); // Detach the thread to allow for automatic resource cleanup
    }

    // Close the server socket (unreachable code in this example)
    close(server_socket);
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = (intptr_t)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received <= 0) {
            printf("Client disconnected\n");
            break; // Client disconnected or error occurred
        }

        buffer[bytes_received] = '\0'; // Null-terminate the received data
        printf("Received from client: %s\n", buffer);

        // Echo back the message to the client
        send(sock, buffer, bytes_received, 0);
    }
    
    close(sock); // Close the client socket
    return NULL;
}

void error_handling(const char *message) {
    perror(message);
    exit(1);
}