//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void handle_client(int client_fd) {
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];
    char method[16], host[256], path[256];
    
    // Read request from the client
    int bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received <= 0) {
        close(client_fd);
        return;
    }

    buffer[bytes_received] = '\0';
    
    // Extract method, host, and path from the HTTP request
    sscanf(buffer, "%s %s %*s", method, request);
    
    // Parsing the request to find the host and path
    if (sscanf(request, "http://%255[^/]/%255s", host, path) < 2) {
        sscanf(request, "http://%255[^/]", host);
        strcpy(path, "");
    }

    printf("Client request: Method: %s, Host: %s, Path: %s\n", method, host, path);

    // Create a socket for the server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) error_exit("Socket creation failed");

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    
    // Resolve address
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        close(client_fd);
        close(server_fd);
        error_exit("Invalid address or address not supported");
    }

    // Connect to the server
    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(client_fd);
        close(server_fd);
        error_exit("Connection to the server failed");
    }

    // Send the original request to the server
    send(server_fd, buffer, bytes_received, 0);

    // Wait for the response from the server
    while ((bytes_received = recv(server_fd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';

        // Forward the response back to the client
        send(client_fd, buffer, bytes_received, 0);
    }

    // Close the sockets
    close(server_fd);
    close(client_fd);
}

int main() {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create the listening socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_exit("Socket creation failed");
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error_exit("Set socket options failed");
    }

    // Initialize address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error_exit("Bind failed");
    }

    // Start listening
    if (listen(server_fd, 3) < 0) {
        error_exit("Listen failed");
    }

    printf("Proxy server running on port %d...\n", PORT);

    while (1) {
        int client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (client_fd < 0) {
            perror("Accept failed");
            continue; // Continue to next iteration
        }
        
        // Handle the client in a separate function
        handle_client(client_fd);
    }

    // Close server socket
    close(server_fd);
    return 0;
}