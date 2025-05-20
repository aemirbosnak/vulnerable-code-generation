//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 8192
#define MAX_CLIENTS 10

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int received_bytes;

    // Receive request from the client
    received_bytes = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (received_bytes < 0) {
        error("Error receiving data");
    }
    buffer[received_bytes] = '\0'; // Null-terminate the received data
    
    // Get target server and port from the HTTP request
    char method[10], url[256];
    sscanf(buffer, "%s %s", method, url);
    
    // Check if the method is GET
    if (strcasecmp(method, "GET") != 0) {
        fprintf(stderr, "Only GET method is supported\n");
        close(client_socket);
        return;
    }

    // Extract host and port from the URL
    char host[256] = {0};
    int port = 80; // Default port for HTTP
    sscanf(url + 7, "%255[^:]:%d", host, &port); // Extract host and port from "http://host:port/resource"
    if (host[0] == '\0') {
        sscanf(url + 7, "%255[^/]", host); // If no port is specified, extract host only
    }

    // Create a socket to connect to the target server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Error creating socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        error("Invalid address / Address not supported");
    }

    // Connect to the target server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to the server failed");
    }

    // Forward the request to the target server
    send(server_socket, buffer, received_bytes, 0);

    // Read the response from the server and send it back to the client
    while ((received_bytes = recv(server_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[received_bytes] = '\0'; // Null-terminate the buffer
        send(client_socket, buffer, received_bytes, 0);
    }

    close(server_socket);
    close(client_socket);
}

void start_proxy() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create a socket for the proxy server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Error creating socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Binding failed");
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        error("Listening failed");
    }

    printf("Proxy server is running on port %d\n", PORT);

    // Main loop to accept and handle client connections
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket < 0) {
            error("Accept failed");
        }

        printf("Accepted a client connection\n");
        handle_client(client_socket);
    }

    close(server_socket);
}

int main() {
    start_proxy();
    return 0;
}