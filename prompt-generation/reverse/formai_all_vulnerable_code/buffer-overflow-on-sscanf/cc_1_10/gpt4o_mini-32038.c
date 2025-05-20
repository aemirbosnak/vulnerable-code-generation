//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 4096

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    char method[16], url[256], protocol[16];

    // Read the request from the client
    int bytes_read = recv(client_sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        perror("Error reading from client");
        close(client_sock);
        return;
    }
    
    buffer[bytes_read] = '\0';
    
    // Parse the request line
    sscanf(buffer, "%s %s %s", method, url, protocol);
    
    // Remove "http://" from the URL if present
    char *hostname = url;
    char *port_pos = strstr(url, ":");
    if (port_pos) {
        *port_pos = '\0';  // Remove port number if present
    }

    // Formulate the destination address
    strcat(url, port_pos ? "" : ":80");

    // Setup the server socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Failed to create socket");
        close(client_sock);
        return;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the remote server
    if (connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_sock);
        close(client_sock);
        return;
    }

    // Send the request to the server
    if (send(server_sock, buffer, bytes_read, 0) < 0) {
        perror("Error sending to server");
        close(server_sock);
        close(client_sock);
        return;
    }

    // Receive the response from the server and send it back to the client
    while ((bytes_read = recv(server_sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        send(client_sock, buffer, bytes_read, 0);
    }

    if (bytes_read < 0) {
        perror("Error reading from server");
    }

    // Close the sockets
    close(server_sock);
    close(client_sock);
}

int main() {
    // Create TCP socket
    int proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock < 0) {
        perror("Failed to create proxy socket");
        return EXIT_FAILURE;
    }

    // Bind the socket to the desired port
    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    if (bind(proxy_sock, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Failed to bind socket");
        close(proxy_sock);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(proxy_sock, 10) < 0) {
        perror("Failed to listen on socket");
        close(proxy_sock);
        return EXIT_FAILURE;
    }

    printf("Proxy server is listening on port %d...\n", PORT);

    while (1) {
        // Accept a client connection
        int client_sock = accept(proxy_sock, NULL, NULL);
        if (client_sock < 0) {
            perror("Failed to accept client connection");
            continue; // Move to next iteration
        }

        // Handle the client in a separate function
        handle_client(client_sock);
    }

    // Close the main socket (this point is never reached in the current loop)
    close(proxy_sock);
    return EXIT_SUCCESS;
}