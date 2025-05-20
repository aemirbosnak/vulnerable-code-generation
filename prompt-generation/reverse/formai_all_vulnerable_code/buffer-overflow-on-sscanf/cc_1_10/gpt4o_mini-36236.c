//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Read the client's request
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive data");
        close(client_socket);
        return;
    }

    printf("Request:\n%s\n", buffer);

    // Extract the first line of the HTTP request
    char method[10], url[256], protocol[10];
    sscanf(buffer, "%s %s %s", method, url, protocol);

    // Get the host and port from the URL
    char host[256];
    int port = 80;
    if (sscanf(url, "http://%255[^:]:%d", host, &port) != 2) {
        sscanf(url, "http://%255[^/]", host); // No port specified
    }

    // Create a new socket to connect to the destination server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Unable to create socket");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(host);

    // Connect to the destination server
    if (connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Send the client's request to the server
    send(server_socket, buffer, bytes_received, 0);

    // Receive the server's response and send it back to the client
    while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0);
    }

    // Clean up
    close(server_socket);
    close(client_socket);
}

int main() {
    int proxy_socket, client_socket;
    struct sockaddr_in proxy_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create a socket for the proxy
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Unable to create proxy socket");
        return EXIT_FAILURE;
    }

    // Prepare the proxy address structure
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = INADDR_ANY;
    proxy_address.sin_port = htons(PORT);

    // Bind the proxy socket to the specified port
    if (bind(proxy_socket, (struct sockaddr*)&proxy_address, sizeof(proxy_address)) < 0) {
        perror("Failed to bind socket");
        close(proxy_socket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(proxy_socket, 10) < 0) {
        perror("Failed to listen");
        close(proxy_socket);
        return EXIT_FAILURE;
    }

    printf("Simple HTTP Proxy Server running on port %d\n", PORT);

    // Accept incoming connections and handle them
    while (1) {
        client_socket = accept(proxy_socket, (struct sockaddr*)&client_address, &client_address_len);
        if (client_socket < 0) {
            perror("Failed to accept client connection");
            continue;
        }

        handle_client(client_socket);
    }

    // Clean up
    close(proxy_socket);
    return EXIT_SUCCESS;
}