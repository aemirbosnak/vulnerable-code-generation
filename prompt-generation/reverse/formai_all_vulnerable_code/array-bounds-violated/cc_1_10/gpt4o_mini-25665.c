//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 8192

void handle_client(int client_socket);
void forward_request(int client_socket, const char *host, int port, const char *request);
void send_response(int client_socket, int server_socket);

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

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, 10) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("HTTP Proxy Server is running on port %d...\n", PORT);

    // Main loop to accept clients
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
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
    ssize_t n = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (n <= 0) {
        perror("Receive failed");
        return;
    }

    buffer[n] = '\0';  // Null-terminate the received data
    printf("Received request:\n%s\n", buffer);

    // Parse the request to get the host and port
    char method[10], url[100], version[10];
    sscanf(buffer, "%s %s %s", method, url, version);
    char *hostname = url + 7; // Skip "http://"
    char *port = strchr(hostname, ':');
    if (port) {
        *port = '\0';
        port++;
    } else {
        port = "80"; // Default HTTP port
    }

    // Forward the request to the actual server
    forward_request(client_socket, hostname, atoi(port), buffer);
}

void forward_request(int client_socket, const char *host, int port, const char *request) {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create socket to server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket to server creation failed");
        return;
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect to server failed");
        close(server_socket);
        return;
    }

    // Send the HTTP request
    send(server_socket, request, strlen(request), 0);

    // Send the response back to the client
    send_response(client_socket, server_socket);

    close(server_socket);
}

void send_response(int client_socket, int server_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t n;

    while ((n = recv(server_socket, buffer, sizeof(buffer), 0)) > 0) {
        send(client_socket, buffer, n, 0);
    }
}