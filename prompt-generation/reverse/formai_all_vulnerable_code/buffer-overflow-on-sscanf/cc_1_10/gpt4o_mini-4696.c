//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket);
void send_request_to_server(int client_socket, const char *hostname, int port, const char *request);
void handle_client_response(int server_socket, int client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Defining server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return 1;
    }

    // Listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        return 1;
    }

    printf("Proxy server is running on port %d\n", PORT);

    while (1) {
        client_len = sizeof(client_addr);
        // Accepting client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("Accept failed");
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
    ssize_t bytes_read;

    // Reading request from client
    bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0) {
        perror("Failed to read request");
        return;
    }
    buffer[bytes_read] = '\0';

    // Extracting the hostname from the request
    char method[16], url[512], protocol[16];
    sscanf(buffer, "%s %s %s", method, url, protocol);

    // Assuming the request is HTTP and extracting the host
    char *hostname = strtok(url + 7, "/"); // Skip "http://"

    send_request_to_server(client_socket, hostname, 80, buffer);
}

void send_request_to_server(int client_socket, const char *hostname, int port, const char *request) {
    int server_socket;
    struct sockaddr_in server_addr;
    
    // Creating socket for the target server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation for server failed");
        return;
    }

    // Defining target server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname); // Convert hostname to IP

    // Connecting to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        close(server_socket);
        return;
    }

    // Sending the request to the server
    send(server_socket, request, strlen(request), 0);

    // Handle response from the server
    handle_client_response(server_socket, client_socket);
    close(server_socket);
}

void handle_client_response(int server_socket, int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Reading response from the server
    while ((bytes_read = recv(server_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        // Forwarding the response back to the client
        send(client_socket, buffer, bytes_read, 0);
    }

    if (bytes_read < 0) {
        perror("Failed to read response from the server");
    }
}