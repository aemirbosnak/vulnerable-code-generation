//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT 8888
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void handle_client(int client_fd) {
    char buffer[BUFFER_SIZE];
    int received_bytes = recv(client_fd, buffer, BUFFER_SIZE, 0);
    if (received_bytes < 0) {
        error("Error receiving data");
    }

    buffer[received_bytes] = '\0'; // Null-terminate the received data
    printf("Received request:\n%s\n", buffer);

    // Parse the request to get the host and port
    char method[10], host[256], path[256];
    int port = 80; // Default HTTP port
    sscanf(buffer, "%s http://%[^:]:%d/%s", method, host, &port, path);
    
    // If port is not specified, default to 80
    if (strstr(buffer, "http://") != NULL && !strchr(buffer, ':')) {
        sscanf(buffer, "%s http://%[^/]/%s", method, host, path);
    }

    // Create server connection
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        error("Error opening socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        error("Invalid host address");
    }

    // Connect to the real server
    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to server failed");
    }

    // Forward the request to the real server
    send(server_fd, buffer, received_bytes, 0);

    // Get the response from the server and send it back to the client
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(server_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) break; // Exit on error or EOF
        send(client_fd, buffer, bytes_received, 0);
    }

    close(server_fd);
    close(client_fd);
}

int main() {
    int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd < 0) {
        error("Could not create socket");
    }

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    if (bind(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        error("Bind failed");
    }

    if (listen(proxy_fd, 5) < 0) {
        error("Listen failed");
    }

    printf("Proxy server is running on port %d...\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(proxy_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) {
            error("Accept failed");
        }

        // Handle client in separate process
        if (fork() == 0) {
            close(proxy_fd); // Child does not need the listening socket
            handle_client(client_fd);
            exit(0);
        }
        
        close(client_fd); // Parent closes the connected socket
    }

    close(proxy_fd);
    return 0;
}