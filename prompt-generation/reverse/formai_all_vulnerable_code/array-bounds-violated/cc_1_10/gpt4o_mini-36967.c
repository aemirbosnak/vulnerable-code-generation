//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes_read < 0) {
        error("Error reading from socket");
    }
    
    buffer[bytes_read] = '\0'; // Null-terminate the buffer

    // Parse the HTTP request
    char method[16], url[256], protocol[16];
    sscanf(buffer, "%s %s %s", method, url, protocol);

    // Check if it's a GET request
    if (strcmp(method, "GET") != 0) {
        const char *error_response = "HTTP/1.1 501 Not Implemented\r\n\r\n";
        send(client_sock, error_response, strlen(error_response), 0);
        close(client_sock);
        return;
    }

    // Extract the hostname and path
    char hostname[256], path[256];
    if (sscanf(url, "http://%255[^/]/%255c", hostname, path) < 1) {
        const char *error_response = "HTTP/1.1 400 Bad Request\r\n\r\n";
        send(client_sock, error_response, strlen(error_response), 0);
        close(client_sock);
        return;
    }

    // Prepare the HTTP request to the target server
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET /%s %s\r\nHost: %s\r\nConnection: close\r\n\r\n", path, protocol, hostname);

    // Connect to the target server
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        error("Could not create socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change this to resolve to the actual server if needed

    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to server failed");
    }

    // Send request to target server
    send(server_sock, request, strlen(request), 0);

    // Receive response from target server and forward to client
    while ((bytes_read = recv(server_sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer 
        send(client_sock, buffer, bytes_read, 0);
    }

    // Close sockets
    close(server_sock);
    close(client_sock);
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        error("Could not create socket");
    }

    // Bind socket to the specified port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Bind failed");
    }

    // Start listening for incoming connections
    if (listen(server_sock, 5) < 0) {
        error("Listen failed");
    }

    printf("Proxy server is running on port %d\n", PORT);

    // Accept and handle client connections
    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            error("Accept failed");
        }

        handle_client(client_sock);
    }

    // Close server socket (this line will never be reached)
    close(server_sock);
    return 0;
}