//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define PORT 8080

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (received <= 0) {
        fprintf(stderr, "Error receiving data\n");
        close(client_socket);
        return;
    }

    buffer[received] = '\0'; // Null terminate the received buffer

    // Parse the request line for host and port
    char method[10], url[2048], version[10];
    sscanf(buffer, "%s %s %s", method, url, version);

    // Set default port
    int port = 80; 

    // Basic URL parsing (ignoring protocol for simplicity)
    char host[256] = {0};
    sscanf(url, "http://%255[^:/]:%d", host, &port);
    if (strlen(host) == 0) {
        sscanf(url, "http://%255[^:/]", host);
    }

    // Create a socket to contact the actual server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Forward the request to the server
    send(server_socket, buffer, received, 0);

    // Receive the response from the server
    while ((received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        // Send the response back to the client
        send(client_socket, buffer, received, 0);
    }
    
    if (received < 0) {
        fprintf(stderr, "Error receiving response from server\n");
    }

    // Close sockets
    close(server_socket);
    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listening failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("Simple HTTP Proxy Server running on port %d\n", PORT);

    while (1) {
        // Accept incoming connections
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Continue to accept more clients
        }

        // Handle the client connection in a new function
        handle_client(client_socket);
    }

    // Close the server socket (unreachable in this example)
    close(server_socket);
    return EXIT_SUCCESS;
}