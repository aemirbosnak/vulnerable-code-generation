//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 4096

void handle_client(int client_socket);
void forward_request(int client_socket, const char *request, size_t request_len);
void relay_response(int client_socket, int server_socket);
void close_connection(int socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close_connection(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) < 0) {
        perror("Listen failed");
        close_connection(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        printf("Accepted connection from client\n");
        handle_client(client_socket);
        close_connection(client_socket);
    }

    close_connection(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t request_len = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (request_len < 0) {
        perror("Receive failed");
        return;
    }

    buffer[request_len] = '\0';
    printf("Received request:\n%s", buffer);

    // Forward the request to the server
    forward_request(client_socket, buffer, request_len);
}

void forward_request(int client_socket, const char *request, size_t request_len) {
    char host[256] = {0};
    sscanf(request, "GET http://%255[^:]:", host);

    struct sockaddr_in server_addr;
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Could not create server socket");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34"); // Example IP for example.com

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close_connection(server_socket);
        return;
    }

    send(server_socket, request, request_len, 0);
    printf("Forwarded request to server\n");

    // Relay the server's response back to the client
    relay_response(client_socket, server_socket);

    close_connection(server_socket);
}

void relay_response(int client_socket, int server_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = recv(server_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        send(client_socket, buffer, bytes_read, 0);
    }
    if (bytes_read < 0) {
        perror("Failed to receive response from server");
    }
    printf("Completed relaying response to client\n");
}

void close_connection(int socket) {
    if (socket > 0) {
        close(socket);
        printf("Closed connection\n");
    }
}