//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket);
void error_handling(const char *message);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;

    // Create socket
    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error_handling("socket() error");
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind() error");
    }

    // Listen
    if (listen(server_socket, 5) == -1) {
        error_handling("listen() error");
    }
    printf("Proxy server running on port %d...\n", PORT);

    while (1) {
        // Accept client connections
        client_addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            perror("accept() error");
            continue;
        }

        handle_client(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char method[16], url[255], protocol[16];
    sscanf(buffer, "%s %s %s", method, url, protocol);

    // Validate HTTP method
    if (strcasecmp(method, "GET") != 0) {
        send(client_socket, "HTTP/1.1 405 Method Not Allowed\r\n\r\n", 37, 0);
        return;
    }

    // Extract hostname and port
    char hostname[255];
    int port = 80; // default HTTP port
    char *host_start = strstr(url, "://");
    if (host_start) {
        host_start += 3; // Skip "://"
    } else {
        host_start = url; // No scheme, process the URL directly
    }

    char *path_start = strchr(host_start, '/');
    if (path_start) {
        *path_start = '\0'; // Split hostname and path
    }

    // Check for port in hostname
    char *port_colon = strchr(host_start, ':');
    if (port_colon) {
        *port_colon = '\0';
        port = atoi(port_colon + 1);
    }

    sscanf(host_start, "%s", hostname);
    if (path_start) {
        *path_start = '/'; // Restore path for further processing
    } else {
        path_start = ""; // No path provided
    }
    
    // Connect to target server
    int server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error_handling("socket() error while connecting to server");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Establish connection
    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect() error");
    }

    // Forward request to target server
    snprintf(buffer, sizeof(buffer), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path_start, hostname);
    send(server_socket, buffer, strlen(buffer), 0);

    // Relay response to client
    ssize_t bytes_received;
    while ((bytes_received = recv(server_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate string
        send(client_socket, buffer, bytes_received, 0);
    }

    close(server_socket);
}

void error_handling(const char *message) {
    perror(message);
    exit(1);
}