//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8888
#define BUFFER_SIZE 8192

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char *request_line;
    char method[10], url[256], protocol[10];
    struct sockaddr_in server_addr;
    int server_socket;

    // Receive request from client
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(client_socket);
        return;
    }

    buffer[bytes_received] = '\0'; // Null-terminate the buffer
    printf("Received request:\n%s\n", buffer);
    
    // Parse the request line
    request_line = strtok(buffer, "\r\n");
    sscanf(request_line, "%s %s %s", method, url, protocol);

    // Open socket to connect to the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        close(client_socket);
        return;
    }

    // Extract host and port
    char host[256];
    int port = 80; // Default HTTP port
    char *host_start = strstr(url, "://");
    if (host_start) {
        host_start += 3; // Skip "://"
    } else {
        host_start = url; // No "://", take the whole URL
    }
    
    char *path_start = strchr(host_start, '/');
    if (path_start) {
        strncpy(host, host_start, path_start - host_start);
        host[path_start - host_start] = '\0';
    } else {
        strcpy(host, host_start);
    }
    
    char *port_pos = strchr(host, ':');
    if (port_pos) {
        *port_pos = '\0'; // Split host and port
        port = atoi(port_pos + 1);
    }

    // Configure the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Connect to the server
    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Forward the request to the server
    send(server_socket, buffer, bytes_received, 0);

    // Receive the response from the server
    while ((bytes_received = recv(server_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        send(client_socket, buffer, bytes_received, 0); // Send response back to the client
    }

    // Clean up
    close(server_socket);
    close(client_socket);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket for the proxy server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Configure the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("HTTP Proxy Server Listening on port %d\n", PORT);

    while (1) {
        // Accept an incoming client connection
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("accept");
            continue; // Handle next connection
        }

        // Handle the client request in a separate function
        handle_client(client_socket);
    }

    // Clean up
    close(server_socket);
    return 0;
}