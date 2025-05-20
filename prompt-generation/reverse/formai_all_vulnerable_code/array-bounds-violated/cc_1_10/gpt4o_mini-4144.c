//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096
#define PORT 8080

void handle_client(int client_socket);
void forward_request(int client_socket, char *request, char *host, int port);
void parse_request(char *request, char *host, int *port);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("HTTP Proxy Server is running on port %d\n", PORT);

    // Accept clients
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accepted failed");
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
    int bytes_received;

    // Receive request from the client
    bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received <= 0) {
        perror("Receive failed");
        return;
    }

    buffer[bytes_received] = '\0'; // Null-terminate the string

    // Parse the host and port from the request
    char host[256];
    int port = 80; // Default port for HTTP
    parse_request(buffer, host, &port);

    // Forward the request to the actual server
    forward_request(client_socket, buffer, host, port);
}

void forward_request(int client_socket, char *request, char *host, int port) {
    int server_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket for connecting to the destination server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation for server connection failed");
        return;
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_socket);
        return;
    }

    // Forward the request to the server
    send(server_socket, request, strlen(request), 0);

    // Receive the response from the server and forward it back to the client
    int bytes_received;
    while ((bytes_received = recv(server_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0);
    }

    close(server_socket);
}

void parse_request(char *request, char *host, int *port) {
    // Simple request parsing to improve robustness
    char *start = strstr(request, "Host: ");
    if (start) {
        start += strlen("Host: ");
        char *end = strchr(start, '\r');
        if (end) {
            *end = '\0'; // Null-terminate the host string
            strcpy(host, start);

            // Check if custom port is specified
            char *colon = strchr(host, ':');
            if (colon) {
                *colon = '\0'; // Separate host and port
                *port = atoi(colon + 1);
            }
        }
    }
}