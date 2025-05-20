//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 8192

// Function to handle the client's request
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char method[10], url[256], version[10];
    
    // Read the request from the client
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(client_socket);
        return;
    }
    buffer[bytes_received] = '\0'; // Null-terminate the buffer

    // Tokenize the request line
    sscanf(buffer, "%s %s %s", method, url, version);
    
    printf("Received request: %s %s %s\n", method, url, version);

    // Create a connection to the target server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34"); // Example for example.com

    // Connect to the target server
    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(server_socket);
        close(client_socket);
        return;
    }
    
    // Forward the request to the target server
    send(server_socket, buffer, bytes_received, 0);
    
    // Get the response from the target server
    while ((bytes_received = recv(server_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        // Send the response back to the client
        send(client_socket, buffer, bytes_received, 0);
    }

    // Close the sockets
    close(server_socket);
    close(client_socket);
}

// Main function to set up the proxy server
int main() {
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(PORT);
    proxy_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(proxy_socket, (struct sockaddr*) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("bind");
        close(proxy_socket);
        return EXIT_FAILURE;
    }

    // Start listening for incoming connections
    if (listen(proxy_socket, 5) < 0) {
        perror("listen");
        close(proxy_socket);
        return EXIT_FAILURE;
    }

    printf("Proxy server listening on port %d...\n", PORT);

    // Accept incoming connections in a loop
    while (1) {
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept");
            continue; // Handle error and continue
        }

        // Handle the client's request in a separate function
        handle_client(client_socket);
    }

    // Close the proxy socket (this line is never reached in this demo)
    close(proxy_socket);
    return EXIT_SUCCESS;
}