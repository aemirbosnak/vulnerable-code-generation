//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 8192
#define PORT 8080

void handle_client(int client_sock);
void forward_request(int client_sock, const char *hostname, int server_port);
void read_from_server(int server_sock, int client_sock);
void write_to_client(int client_sock, const char *data, size_t size);
void error_exit(const char *message);

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        error_exit("Socket creation failed");
    }
    
    // Bind socket
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        close(server_sock);
        error_exit("Binding failed");
    }

    // Listen for incoming connections
    if (listen(server_sock, 10) < 0) {
        close(server_sock);
        error_exit("Listening failed");
    }

    printf("Proxy server listening on port %d...\n", PORT);

    // Main loop to accept clients
    while (1) {
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }
        handle_client(client_sock);
        close(client_sock);
    }

    close(server_sock);
    return 0;
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Read request from client
    bytes_read = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0) {
        perror("Receive failed");
        return;
    }

    // Null-terminate to treat it as a string
    buffer[bytes_read] = '\0';

    // Extract hostname from the request
    char *host_start = strstr(buffer, "Host: ");
    if (!host_start) {
        write_to_client(client_sock, "HTTP/1.1 400 Bad Request\r\n\r\n", 30);
        return;
    }
    host_start += 6; // Move pointer to the end of "Host: "
    char *host_end = strstr(host_start, "\r\n");
    if (!host_end) {
        write_to_client(client_sock, "HTTP/1.1 400 Bad Request\r\n\r\n", 30);
        return;
    }
    *host_end = '\0'; // Null-terminate the hostname

    // Forward request to the specified host
    forward_request(client_sock, host_start, 80); // Default HTTP port
}

void forward_request(int client_sock, const char *hostname, int server_port) {
    int server_sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_sent, bytes_read;

    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation for server failed");
        return;
    }

    // Specify server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the server
    if (connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_sock);
        return;
    }

    // Send the client's request to the server
    bytes_sent = send(server_sock, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Send to server failed");
        close(server_sock);
        return;
    }

    // Read the response from the server
    read_from_server(server_sock, client_sock);
    close(server_sock);
}

void read_from_server(int server_sock, int client_sock) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = recv(server_sock, buffer, sizeof(buffer), 0)) > 0) {
        write_to_client(client_sock, buffer, bytes_read);
    }
    
    if (bytes_read < 0) {
        perror("Receive from server failed");
    }
}

void write_to_client(int client_sock, const char *data, size_t size) {
    ssize_t bytes_sent = send(client_sock, data, size, 0);
    if (bytes_sent < 0) {
        perror("Send to client failed");
    }
}

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}