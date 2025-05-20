//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 8192

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char method[10], url[256], protocol[10];
    char host[256], request[BUFFER_SIZE];
    int bytes_read;

    // Read the request from the client
    bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0) {
        perror("recv failed");
        close(client_socket);
        return;
    }
    buffer[bytes_read] = '\0'; // Null terminate buffer

    // Parse the request line
    sscanf(buffer, "%s %s %s", method, url, protocol);
    printf("Method: %s, URL: %s, Protocol: %s\n", method, url, protocol);

    // Strip off 'http://' from the URL to extract host
    char *host_start = strstr(url, "://");
    if (host_start) {
        host_start += 3; // Move past 'http://'
    } else {
        host_start = url;
    }

    char *host_end = strchr(host_start, '/');
    if (host_end) {
        strncpy(host, host_start, host_end - host_start);
        host[host_end - host_start] = '\0'; // Null terminate
    } else {
        strcpy(host, host_start);
    }

    printf("Host: %s\n", host);

    // Create a socket to connect to the target server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        close(client_socket);
        return;
    }

    // Set up the server address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Use port 80 for HTTP
    server_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Send the request to the target server
    sprintf(request, "%s %s %s\r\nHost: %s\r\nConnection: close\r\n\r\n", method, url, protocol, host);
    send(server_socket, request, strlen(request), 0);

    // Receive the response from the server and send it back to the client
    while ((bytes_read = recv(server_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null terminate the buffer
        send(client_socket, buffer, bytes_read, 0);
    }

    // Clean up
    close(server_socket);
    close(client_socket);
}

int main() {
    // Create a socket for the proxy server
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    proxy_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Failed to bind");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(proxy_socket, 10) < 0) {
        perror("Failed to listen");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy Server running on port %d...\n", PORT);

    // Run the server loop
    while (1) {
        // Accept an incoming connection
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Failed to accept");
            continue;
        }

        // Handle the client request
        handle_client(client_socket);
    }

    close(proxy_socket);
    return 0;
}