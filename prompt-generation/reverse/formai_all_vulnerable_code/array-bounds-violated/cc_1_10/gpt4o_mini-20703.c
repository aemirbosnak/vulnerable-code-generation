//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket);
void forward_request(int client_socket, const char *target_host, int target_port);
void send_error(int client_socket, const char *message);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
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

    printf("Proxy server is running on port %d...\n", PORT);

    while (1) {
        // Accept a new client connection
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
    int bytes_received;

    // Read the request from the client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Recv failed");
        send_error(client_socket, "Error receiving data from client");
        return;
    }
    buffer[bytes_received] = '\0';  // Null-terminate the string

    // Parse the HTTP request
    char method[10], url[200];
    sscanf(buffer, "%s %s", method, url);
    
    if (strcmp(method, "GET") != 0) {
        send_error(client_socket, "Only GET method is supported");
        return;
    }

    // Get target host and port
    char target_host[100];
    int target_port = 80;

    // Parsing the URL
    char *host_start = strstr(url, "://");
    if (host_start) {
        host_start += 3;  // Skip past the "://"
    } else {
        host_start = url; // If no schema, just use the URL directly
    }

    char *host_end = strchr(host_start, '/');
    if (host_end) {
        strncpy(target_host, host_start, host_end - host_start);
        target_host[host_end - host_start] = '\0';
    } else {
        strcpy(target_host, host_start);  // No path, so copy whole host
    }

    // Forward the request to the target server
    forward_request(client_socket, target_host, target_port);
}

void forward_request(int client_socket, const char *target_host, int target_port) {
    int server_socket;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE];

    // Create a socket for the target server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        send_error(client_socket, "Error creating server socket");
        return;
    }

    // Configure target server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target_port);
    server_addr.sin_addr.s_addr = inet_addr(target_host);

    // Connect to the target server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        send_error(client_socket, "Error connecting to target server");
        close(server_socket);
        return;
    }

    // Send the request to the target server
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", target_host);
    send(server_socket, request, strlen(request), 0);

    // Read response from target server and send it back to client
    char response[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(server_socket, response, sizeof(response)-1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        send(client_socket, response, bytes_received, 0);
    }

    close(server_socket);
}

void send_error(int client_socket, const char *message) {
    char response[BUFFER_SIZE];
    snprintf(response, sizeof(response),
             "HTTP/1.1 500 Internal Server Error\r\n"
             "Content-Type: text/plain\r\n"
             "Connection: close\r\n"
             "\r\n"
             "%s", message);
    send(client_socket, response, strlen(response), 0);
}