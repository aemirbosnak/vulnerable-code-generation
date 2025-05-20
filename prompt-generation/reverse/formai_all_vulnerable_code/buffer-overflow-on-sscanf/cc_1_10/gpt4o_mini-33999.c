//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 8192

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char method[16], url[256], protocol[16];
    int bytes_received;

    // Read request from client
    bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received < 1) {
        perror("recv failed");
        close(client_socket);
        return;
    }

    // Parse HTTP request
    sscanf(buffer, "%s %s %s", method, url, protocol);

    // Prepare request for the remote server
    char *host_start = strstr(url, "://");
    if (host_start) {
        host_start += 3; // Move past "://"
    } else {
        host_start = url; // No protocol, assume straight URL
    }
    
    char *host_end = strchr(host_start, '/');
    if (!host_end) host_end = host_start + strlen(host_start);

    size_t host_length = host_end - host_start;
    char host[host_length + 1];
    strncpy(host, host_start, host_length);
    host[host_length] = '\0';

    // Create a socket to connect to the destination server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket to server failed");
        close(client_socket);
        return;
    }

    // Set up the server address struct
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port

    // Convert the host address to binary form
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("invalid address");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection to server failed");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Forward the request to the server
    send(server_socket, buffer, bytes_received, 0);

    // Receive the response from the server and send it back to the client
    while ((bytes_received = recv(server_socket, buffer, sizeof(buffer), 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0);
    }

    // Close the sockets
    close(server_socket);
    close(client_socket);
}

int main() {
    int proxy_socket, client_socket;
    struct sockaddr_in proxy_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // Create a socket for the proxy
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the proxy address struct
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY; // Bind to any interface
    proxy_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("bind failed");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(proxy_socket, 5) < 0) {
        perror("listen failed");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    printf("Simple HTTP Proxy listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming client connections
        client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("accept failed");
            continue;
        }

        // Handle client request
        handle_client(client_socket);
    }

    close(proxy_socket);
    return 0;
}