//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096
#define PORT 8080

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Read the request from the client
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("Socket error!");
        close(client_socket);
        return;
    }

    // Log the request into a neon database (console)
    printf("Request:\n%s\n", buffer);
    
    // Parse the request to find the requested resource
    char method[10], url[256];
    sscanf(buffer, "%s %s", method, url);

    // Open a connection to the requested server in the neon-lit city
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket!");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Standard HTTP port

    // Convert the URL to IP Address (only handle localhost for simplicity)
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server (might be a shady back alley server)
    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed!");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Send the request to the server
    send(server_socket, buffer, bytes_received, 0);

    // Prepare to receive response
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received_from_server;

    // Relay the server's response back to the client
    while ((bytes_received_from_server = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_socket, buffer, bytes_received_from_server, 0);
    }

    // Log the response (in this world, every byte counts)
    printf("Response sent to client (%d bytes)\n", bytes_received_from_server);

    // Close the sockets
    close(server_socket);
    close(client_socket);
}

int main() {
    // The neon glow of the city seeps through the smoke as we start the proxy
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Choked! Failed to create socket!");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    // Bind the socket to the neon-lit streets
    if (bind(server_socket, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Failed to bind socket!");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming clients; the cyber clients are waiting
    if (listen(server_socket, 5) < 0) {
        perror("Failed to listen!");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("=== Cyberpunk HTTP Proxy is Live on Port %d ===\n", PORT);

    // Accept and handle clients in the neon jungle
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Failed to accept client connection!");
            continue;
        }

        // Spawn a new thread to handle the client (the future is multitasking)
        handle_client(client_socket);
    }

    // Clean up the resources
    close(server_socket);
    return 0;
}