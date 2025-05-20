//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket);
void error(const char *msg);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Error creating socket");
    }

    // Set up the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Binding failed");
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        error("Listening failed");
    }
    
    printf("Proxy server running on port %d...\n", PORT);

    while (1) {
        // Accept a client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            error("Accepting client failed");
        }

        printf("Client connected\n");
        
        // Handle the client request
        handle_client(client_socket);
        
        // Close the client socket
        close(client_socket);
        printf("Client disconnected\n");
    }

    // Close the server socket (never reached in this example)
    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    // Read data from client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received <= 0) {
        fprintf(stderr, "Failed to read from client\n");
        return;
    }
    buffer[bytes_received] = '\0'; // null-terminate the string

    printf("Request:\n%s\n", buffer);
    
    // Parse the request to get the hostname and port
    char method[10], host[100], path[100];
    int port = 80; // Default HTTP port
    sscanf(buffer, "%s http://%99[^:/]:%d/%99[^\n]", method, host, &port, path);
    
    // Establish connection to the target server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Error creating socket for target server");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to target server failed");
    }

    // Forward the request to the target server
    send(server_socket, buffer, bytes_received, 0);

    // Receive the response from the target server
    while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // null-terminate the buffer
        send(client_socket, buffer, bytes_received, 0);
    }

    // Close the socket to the server
    close(server_socket);
}

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}