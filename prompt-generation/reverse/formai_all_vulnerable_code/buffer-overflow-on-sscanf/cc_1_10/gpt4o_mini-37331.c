//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 8192

void handle_client(int client_socket);
void error(const char *msg);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Error creating socket");
    }

    // Set up the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error binding socket");
    }

    // Listen for incoming connections
    listen(server_socket, 5);
    printf("Proxy server listening on port %d\n", PORT);

    // Accept connections in a loop
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Error on accept");
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
    char method[10], url[BUFFER_SIZE], protocol[10];
    
    // Read the request from the client
    int bytes_read = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_read < 0) {
        perror("Error reading from socket");
        return;
    }

    // Ensure we null-terminate the buffer
    buffer[bytes_read] = '\0';

    // Parse the request
    sscanf(buffer, "%s %s %s", method, url, protocol);

    if (strcmp(method, "GET") != 0 && strcmp(method, "POST") != 0) {
        fprintf(stderr, "Unsupported method: %s\n", method);
        return;
    }

    // Get the host and port
    char host[BUFFER_SIZE];
    int port = 80; // default HTTP port
    sscanf(url, "http://%[^:/]:%d", host, &port);
    if (port == 0) {
        sscanf(url, "http://%[^:/]", host);
    }

    // Create socket to connect to the target server
    int target_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (target_socket < 0) {
        error("Error creating target socket");
    }

    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(port);
    
    // Convert host to binary
    if (inet_pton(AF_INET, host, &target_addr.sin_addr) <= 0) {
        error("Invalid host address");
    }

    // Connect to the target server
    if (connect(target_socket, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
        error("Error connecting to the target server");
    }

    // Forward the request to the target server
    send(target_socket, buffer, bytes_read, 0);

    // Read the response from the target server and send it back to the client
    while ((bytes_read = recv(target_socket, buffer, sizeof(buffer), 0)) > 0) {
        send(client_socket, buffer, bytes_read, 0);
    }

    if (bytes_read < 0) {
        perror("Error reading from target socket");
    }

    close(target_socket);
}

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}