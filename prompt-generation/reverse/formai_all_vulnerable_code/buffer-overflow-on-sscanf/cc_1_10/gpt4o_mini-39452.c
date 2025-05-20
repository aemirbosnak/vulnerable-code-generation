//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    // Read request from client
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Error reading from socket");
        close(client_socket);
        return;
    }

    // Print the request for debugging
    printf("Request received:\n%s\n", buffer);

    // Parse the first line of the request to get the URL
    char method[10], host[256], path[256];
    sscanf(buffer, "%s http://%[^/]%s", method, host, path);

    // Compose the HTTP request to send to the real server
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "%s %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", method, path, host);

    // Create a socket to communicate with the actual server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Could not create socket");
        close(client_socket);
        return;
    }

    // Setup server address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    server_addr.sin_addr.s_addr = inet_addr(host); // Convert from string to binary form

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Send HTTP request to the server
    send(server_socket, request, strlen(request), 0);

    // Receive response from the server and send it back to the client
    while ((bytes_received = recv(server_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0);
    }

    // Close sockets
    close(server_socket);
    close(client_socket);
}

int main() {
    // Create a socket to listen for incoming connections
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Could not create socket");
        return 1;
    }

    // Setup address structure for the proxy server
    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY; // Bind to any address
    proxy_addr.sin_port = htons(PORT); // Specified port

    // Bind the socket
    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Binding failed");
        close(proxy_socket);
        return 1;
    }

    // Start listening for connections
    if (listen(proxy_socket, 5) < 0) {
        perror("Could not listen on socket");
        close(proxy_socket);
        return 1;
    }

    printf("Proxy server is running on port %d...\n", PORT);

    // Main loop to accept connections
    while (1) {
        // Accept a new client connection
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Handle the client in a separate function
        handle_client(client_socket);
    }

    // Close the proxy socket (never reached in this example)
    close(proxy_socket);
    return 0;
}