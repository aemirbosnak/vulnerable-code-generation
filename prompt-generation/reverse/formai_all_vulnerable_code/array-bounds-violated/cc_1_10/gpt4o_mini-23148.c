//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char method[16], url[256], version[16];
    
    // Read the request
    recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    printf("Request: %s\n", buffer);

    // Parse the request line
    sscanf(buffer, "%s %s %s", method, url, version);
    
    if (strcasecmp(method, "GET") != 0) {
        fprintf(stderr, "Only GET method is supported.\n");
        close(client_socket);
        return;
    }

    // Find the host
    char host[256];
    char *host_start = strstr(url, "//") + 2;
    char *host_end = strchr(host_start, '/');
    if (host_end) {
        strncpy(host, host_start, host_end - host_start);
        host[host_end - host_start] = '\0';
    } else {
        strncpy(host, host_start, sizeof(host) - 1);
        host[sizeof(host) - 1] = '\0';
    }

    // Connect to the target host
    int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (remote_socket < 0) {
        perror("Socket creation failed");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(remote_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to remote server failed");
        close(remote_socket);
        close(client_socket);
        return;
    }

    // Forward the request to the remote server
    send(remote_socket, buffer, strlen(buffer), 0);
    
    // Receive response from the server and relay back to the client
    int bytes_read;
    while ((bytes_read = recv(remote_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null terminate the received data
        send(client_socket, buffer, bytes_read, 0);
    }

    // Clean up
    close(remote_socket);
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create a server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Proxy server listening on port %d\n", PORT);

    // Main loop to handle clients
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accepting connection failed");
            continue;
        }

        // Handle the client request in a separate function
        handle_client(client_socket);
    }

    // Clean up (unreachable in this simple example)
    close(server_socket);
    return 0;
}