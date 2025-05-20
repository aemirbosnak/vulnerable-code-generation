//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8888
#define BUFFER_SIZE 4096

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int bytes_read = recv(client_sock, buffer, sizeof(buffer), 0);
    
    if (bytes_read < 0) {
        perror("recv failed");
        close(client_sock);
        return;
    }

    // Parse the request
    char *method = strtok(buffer, " ");
    char *url = strtok(NULL, " ");
    
    // Handling simple GET requests only
    if (method == NULL || strcmp(method, "GET") != 0 || url == NULL) {
        const char *error_response = "HTTP/1.1 400 Bad Request\r\n\r\n";
        send(client_sock, error_response, strlen(error_response), 0);
        close(client_sock);
        return;
    }

    // Extract hostname and port
    char hostname[256];
    int port = 80;  // Default HTTP port
    sscanf(url, "http://%255[^:/]:%d", hostname, &port);
    
    // If no port specified, use default
    if (port == 0) {
        sscanf(url, "http://%255[^/]", hostname);
        port = 80;
    }

    // Build a new request to the target server
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the target server
    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(client_sock);
        return;
    }
    
    // Forward the client's request to the server
    send(server_sock, buffer, bytes_read, 0);

    // Receive the server's response
    while ((bytes_read = recv(server_sock, buffer, sizeof(buffer), 0)) > 0) {
        // Send the server's response back to the client
        send(client_sock, buffer, bytes_read, 0);
    }

    // Clean up
    close(server_sock);
    close(client_sock);
}

int main() {
    int proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(PORT);
    proxy_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(proxy_sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Bind failed");
        close(proxy_sock);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(proxy_sock, 5) < 0) {
        perror("Listen failed");
        close(proxy_sock);
        exit(EXIT_FAILURE);
    }

    printf("Simple HTTP Proxy running on port %d...\n", PORT);

    while (1) {
        int client_sock = accept(proxy_sock, NULL, NULL);
        if (client_sock < 0) {
            perror("Accept failed");
            close(proxy_sock);
            exit(EXIT_FAILURE);
        }

        // Handle the client in a separate function
        handle_client(client_sock);
    }

    // Should never reach here
    close(proxy_sock);
    return 0;
}