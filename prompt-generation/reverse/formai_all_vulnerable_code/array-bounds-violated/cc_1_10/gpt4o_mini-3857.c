//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_sock);
void forward_request(int client_sock, const char *host, int port, const char *request);

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_sock, 10) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server is running on port %d\n", PORT);
    
    while (1) {
        // Accept incoming client connection
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        // Handle the client in a new function
        handle_client(client_sock);
        close(client_sock);  // Close the client socket after handling
    }

    close(server_sock);
    return 0;
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Read the client's request
    bytes_read = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0) {
        perror("Failed to read from client");
        return;
    }
    
    buffer[bytes_read] = '\0';  // Null-terminate the buffer

    // Extract the host from the HTTP request
    char *host_start = strstr(buffer, "Host: ");
    if (host_start == NULL) {
        fprintf(stderr, "Invalid request: Host not found\n");
        return;
    }
    
    host_start += 6;  // Move to the start of host address
    char *host_end = strstr(host_start, "\r\n");
    if (host_end == NULL) {
        fprintf(stderr, "Invalid request: Malformed host\n");
        return;
    }

    *host_end = '\0';  // Null-terminate the host string
    char *host = strdup(host_start);  // Duplicate the host string
    int port = 80;  // Default HTTP port

    // Forward the request to the actual server
    forward_request(client_sock, host, port, buffer);
    free(host);  // Free the duplicated host string
}

void forward_request(int client_sock, const char *host, int port, const char *request) {
    int server_sock;
    struct sockaddr_in server_addr;
    char response[BUFFER_SIZE];

    // Create socket to connect to the actual server
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Could not create socket to server");
        return;
    }

    // Setup server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the server
    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_sock);
        return;
    }

    // Send the request to the server
    send(server_sock, request, strlen(request), 0);

    // Receive the response from the server
    ssize_t bytes_read;
    while ((bytes_read = recv(server_sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_read] = '\0';  // Null-terminate the received data
        send(client_sock, response, bytes_read, 0);  // Send the response back to the client
    }

    if (bytes_read < 0) {
        perror("Failed to read from server");
    }
    close(server_sock);  // Close the server socket
}