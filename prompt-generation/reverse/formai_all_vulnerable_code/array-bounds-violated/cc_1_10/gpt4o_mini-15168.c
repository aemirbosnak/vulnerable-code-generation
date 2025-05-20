//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define PORT 8080

void handle_client(int client_socket);
void forward_request(int client_socket, char *request, size_t request_length);
void send_response(int client_socket, int http_response_code, const char *response_body);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", PORT);

    while (1) {
        // Accept a new client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
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
    ssize_t bytes_received;

    // Read request from client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Receive failed");
        return;
    }
    buffer[bytes_received] = '\0';
    printf("Received request:\n%s\n", buffer);

    // Forward request to the target server
    forward_request(client_socket, buffer, bytes_received);
}

void forward_request(int client_socket, char *request, size_t request_length) {
    int server_socket;
    struct sockaddr_in server_addr;
    char response[BUFFER_SIZE];
    ssize_t bytes_sent, bytes_received;

    // Parse the request to extract hostname and port
    char method[8], url[200], version[20];
    sscanf(request, "%s %s %s", method, url, version);

    // Extract host and port from the URL
    char host[100];
    int port = 80; // Default HTTP port
    if (sscanf(url, "http://%99[^:/]:%d", host, &port) != 2) {
        sscanf(url, "http://%99[^:/]", host);
    }

    // Create socket for target server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation for target server failed");
        send_response(client_socket, 502, "Bad Gateway");
        return;
    }

    // Set up server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // Connect to the target server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to target server failed");
        send_response(client_socket, 404, "Not Found");
        close(server_socket);
        return;
    }

    // Send the request to target server
    bytes_sent = send(server_socket, request, request_length, 0);
    if (bytes_sent < 0) {
        perror("Send to target server failed");
        close(server_socket);
        return;
    }

    // Receive response from target server
    while ((bytes_received = recv(server_socket, response, BUFFER_SIZE, 0)) > 0) {
        send(client_socket, response, bytes_received, 0);
    }

    if (bytes_received < 0) {
        perror("Receive from target server failed");
    }

    close(server_socket);
}

void send_response(int client_socket, int http_response_code, const char *response_body) {
    char response[BUFFER_SIZE];
    snprintf(response, sizeof(response),
             "HTTP/1.1 %d %s\r\n"
             "Content-Length: %zu\r\n"
             "Connection: close\r\n"
             "\r\n"
             "%s",
             http_response_code, 
             response_body, 
             strlen(response_body), 
             response_body);
    send(client_socket, response, strlen(response), 0);
}