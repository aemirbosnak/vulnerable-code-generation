//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 8192
#define PORT 8080

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Read the request from the client
    bytes_read = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0) {
        perror("Failed to read from client");
        close(client_sock);
        return;
    }

    // Null-terminate the request for easier processing
    buffer[bytes_read] = '\0';
    printf("Received request:\n%s\n", buffer);

    // Extract request information (for simplicity, we just take the first line)
    char *request_line = strtok(buffer, "\r\n");
    if (!request_line) {
        fprintf(stderr, "Failed to parse request line.\n");
        close(client_sock);
        return;
    }

    char method[10], url[256], version[10];
    if (sscanf(request_line, "%s %s %s", method, url, version) < 3) {
        fprintf(stderr, "Invalid request line format.\n");
        close(client_sock);
        return;
    }

    // Prepare the request to forward to the destination server
    char *dest_host = strstr(url, "://");
    dest_host = dest_host ? dest_host + 3 : url; // Skip 'http://'
    char *dest_path = strchr(dest_host, '/');
    if (dest_path) {
        *dest_path = '\0'; // Null-terminate the host part
        dest_path++; // Move past the null-terminator
    } else {
        dest_path = ""; // From the last part if no path is present
    }

    // Create a socket to connect to the destination server
    int dest_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (dest_sock < 0) {
        perror("Socket creation failed");
        close(client_sock);
        return;
    }

    // Resolve the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, dest_host, &server_addr.sin_addr);

    // Connect to the destination server
    if (connect(dest_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(dest_sock);
        close(client_sock);
        return;
    }

    // Forward the original request
    char forward_request[BUFFER_SIZE];
    snprintf(forward_request, sizeof(forward_request), "%s %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", method, dest_path, dest_host);
    send(dest_sock, forward_request, strlen(forward_request), 0);

    // Read the response from the destination server
    while ((bytes_read = recv(dest_sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        // Send the response back to the client
        send(client_sock, buffer, bytes_read, 0);
    }

    // Cleanup
    close(dest_sock);
    close(client_sock);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the listening socket
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Proxy server running on port %d...\n", PORT);
    
    // Accept incoming clients
    while (1) {
        int client_sock = accept(server_socket, NULL, NULL);
        if (client_sock < 0) {
            perror("Accepting client failed");
            continue;
        }

        // Handle each client request in a separate context
        handle_client(client_sock);
    }

    close(server_socket);
    return 0;
}