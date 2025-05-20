//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 8192
#define PORT 8888

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Get the request
    ssize_t recv_size = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (recv_size < 0) {
        perror("Error receiving request");
        close(client_socket);
        return;
    }

    // Split the request using the newline to find the HTTP request line
    char method[10], host[256], path[256];
    sscanf(buffer, "%s http://%[^/]%s", method, host, path);
    printf("Request method: %s\n", method);
    printf("Host: %s\n", host);
    printf("Path: %s\n", path);

    // Create a socket to connect to the destination server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Unable to create socket to server");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Send the request to the destination server
    if (send(server_socket, buffer, recv_size, 0) < 0) {
        perror("Error sending request to server");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Receive the response from the server
    while ((recv_size = recv(server_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        send(client_socket, buffer, recv_size, 0);
    }

    // When done, close the sockets
    close(server_socket);
    close(client_socket);
}

int main() {
    int proxy_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create a socket for the proxy server
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Unable to create proxy socket");
        exit(EXIT_FAILURE);
    }

    // Configure the proxy server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(proxy_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(proxy_socket, 10) < 0) {
        perror("Listening failed");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server running on port %d...\n", PORT);

    // Main loop to handle clients
    while (1) {
        client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Continue to accept new clients
        }

        // Handle the client in a separate function
        handle_client(client_socket);
    }

    // Clean up
    close(proxy_socket);
    return 0;
}