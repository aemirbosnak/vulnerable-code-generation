//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket);
void forward_request(int client_socket, const char *hostname, int port, const char *path);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
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

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server is running on port %d\n", PORT);

    // Main loop to accept clients
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // continue accepting other clients
        }
        
        // Handle each client in a separate "recursive" call
        handle_client(client_socket);
    }

    // Close server socket
    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    
    // Read the request
    bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0) {
        perror("Failed to read from client");
        close(client_socket);
        return;
    }
    buffer[bytes_read] = '\0';
    
    // Parse the request to extract host and path
    char method[10], host[100], path[200];
    sscanf(buffer, "%s http://%99[^/]%199[^\n]", method, host, path);
    
    // Forward the request
    forward_request(client_socket, host, 80, path);
    
    // Close the client socket
    close(client_socket);
}

void forward_request(int client_socket, const char *hostname, int port, const char *path) {
    int server_socket;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    int bytes_sent, bytes_received;

    // Create a socket for connecting to the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket for server");
        return;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr); // Convert IPv4 and IPv6 addresses from text to binary form

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        close(server_socket);
        return;
    }

    // Create the HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the GET request to the server
    bytes_sent = send(server_socket, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("Failed to send request to server");
        close(server_socket);
        return;
    }

    // Read the response from the server and send it back to the client
    while ((bytes_received = recv(server_socket, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        send(client_socket, response, bytes_received, 0);
    }

    // Close the connection to the server
    close(server_socket);
}