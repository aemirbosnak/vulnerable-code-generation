//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 8192

void handle_client(int client_socket);
void send_response(int client_socket, const char *response, size_t length);

int main() {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server is running on port %d\n", PORT);

    while (1) {
        int client_socket;
        addr_len = sizeof(client_addr);
        
        // Accept incoming client connections
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Handle client requests in a separate function
        handle_client(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Read the client's request
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Receive failed");
        return;
    }

    // Extract the target host from the request (simplified for demonstration)
    char method[10], url[256];
    sscanf(buffer, "%s %s", method, url);

    printf("Request Method: %s, URL: %s\n", method, url);

    // Open a new connection to the target server
    int server_socket;
    struct sockaddr_in server_addr;
    char *host_start = strstr(url, "://") ? strstr(url, "://") + 3 : url;
    char *host_end = strchr(host_start, '/');
    if (host_end) *host_end = '\0'; // Terminate host string

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); 
    server_addr.sin_addr.s_addr = inet_addr(host_start); // Use DNS resolution in a real-case scenario

    // Create a socket for the server connection
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Server socket creation failed");
        return;
    }

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_socket);
        return;
    }

    // Send the received request to the target server
    send(server_socket, buffer, bytes_received, 0);

    // Read the server's response
    while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        send_response(client_socket, buffer, bytes_received);
    }

    if (bytes_received < 0) {
        perror("Receiving response from server failed");
    }

    close(server_socket);
}

void send_response(int client_socket, const char *response, size_t length) {
    size_t total_sent = 0;
    while (total_sent < length) {
        ssize_t sent_bytes = send(client_socket, response + total_sent, length - total_sent, 0);
        if (sent_bytes < 0) {
            perror("Failed to send response");
            return;
        }
        total_sent += sent_bytes;
    }
}