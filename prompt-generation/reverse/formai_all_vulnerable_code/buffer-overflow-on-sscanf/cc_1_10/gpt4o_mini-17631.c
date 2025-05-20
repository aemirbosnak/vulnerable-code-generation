//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8888
#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    // Read request from client
    ssize_t bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        perror("recv failed");
        close(client_socket);
        return;
    }

    // Parse URL from HTTP request
    char method[10], url[100];
    sscanf(buffer, "%s %s", method, url);
    
    // Extract hostname and port from the URL
    char hostname[100];
    int port = 80;
    if (sscanf(url, "http://%99[^:/]:%d", hostname, &port) != 2) {
        if (sscanf(url, "http://%99[^:/]", hostname) != 1) {
            fprintf(stderr, "Invalid URL format\n");
            close(client_socket);
            return;
        }
    }

    // Create a socket to connect to the target server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket failed");
        close(client_socket);
        return;
    }

    // Setup server address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Establish connection to the target server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Forward the request to the server
    send(server_socket, buffer, bytes_read, 0);
    
    // Read the server's response and send it back to the client
    while ((bytes_read = recv(server_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        send(client_socket, buffer, bytes_read, 0);
    }

    // Cleanup
    close(server_socket);
    close(client_socket);
}

int main() {
    // Create a socket to listen for incoming connections
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setup the address structure for the proxy
    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(PORT);
    proxy_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces

    // Bind the socket
    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("bind failed");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(proxy_socket, 10) < 0) {
        perror("listen failed");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", PORT);

    // Main loop to accept and handle client connections
    while (1) {
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept failed");
            continue; // Handle other clients
        }

        handle_client(client_socket);
    }

    // Cleanup (not reached)
    close(proxy_socket);
    return 0;
}