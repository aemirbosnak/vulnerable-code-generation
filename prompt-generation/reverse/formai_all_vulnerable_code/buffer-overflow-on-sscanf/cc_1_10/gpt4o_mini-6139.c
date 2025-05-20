//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket);
void forward_request(int client_socket, const char* host, int port, char* request);

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("Set socket options failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server is listening on port %d...\n", PORT);

    while (1) {
        int client_socket;
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Connection failed");
            continue;
        }

        // Handle client request
        handle_client(client_socket);
        
        // Close the client socket
        close(client_socket);
    }

    // Close the server socket (never reached)
    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive the HTTP request from the client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Receive failed");
        return;
    }
    buffer[bytes_received] = '\0';

    // Parse the HTTP request to extract host and the request line
    char method[10], path[BUFFER_SIZE], version[10];
    char host[BUFFER_SIZE] = {0};

    sscanf(buffer, "%s %s %s", method, path, version);
    
    // Find the host in the headers
    char* header_start = strstr(buffer, "Host: ");
    if (header_start) {
        sscanf(header_start, "Host: %s", host);
    }

    int port = 80; // default HTTP port
    // Check if there's a port specified in the host
    if (strchr(host, ':')) {
        char* port_ptr = strchr(host, ':');
        port = atoi(port_ptr + 1);
        *port_ptr = '\0'; // Terminate the host string before the port
    }

    // Forward the request to the actual server
    forward_request(client_socket, host, port, buffer);
}

void forward_request(int client_socket, const char* host, int port, char* request) {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create socket for the actual server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket to server creation failed");
        return;
    }

    // Specify the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // Connect to the server
    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_socket);
        return;
    }

    // Send the request to the server
    send(server_socket, request, strlen(request), 0);

    // Receive the response from the server and send it back to the client
    char response_buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(server_socket, response_buffer, BUFFER_SIZE - 1, 0)) > 0) {
        response_buffer[bytes_received] = '\0';
        send(client_socket, response_buffer, bytes_received, 0);
    }

    // Close the server socket
    close(server_socket);
}