//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: cheerful
#include <stdio.h>          // For standard input and output
#include <stdlib.h>         // For memory allocation and process control
#include <string.h>         // For string handling
#include <unistd.h>         // For POSIX API
#include <sys/socket.h>     // For socket programming
#include <netinet/in.h>     // For sockaddr_in structure
#include <fcntl.h>          // For file control options

#define PORT 8080           // The port on which the proxy will listen
#define BUFFER_SIZE 4096    // Buffer size for reading data
#define BACKLOG 10          // Max number of pending connections

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    char method[10], url[100]; // Adjust size as necessary
    int nbytes;

    // Read the HTTP request
    nbytes = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (nbytes < 0) {
        perror("Failed to read request");
        close(client_socket);
        return;
    }
    buffer[nbytes] = '\0'; // Null-terminate the request

    // Parse the request line (method and URL)
    sscanf(buffer, "%s %s", method, url);
    printf("Method: %s\n", method);
    printf("URL: %s\n", url);

    // Create a socket for connecting to the target server
    int target_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (target_socket < 0) {
        perror("Failed to create socket");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with target server's IP

    // Connect to the target server
    if (connect(target_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to target server");
        close(client_socket);
        close(target_socket);
        return;
    }

    // Send the request to the target server
    send(target_socket, buffer, nbytes, 0);

    // Receive the response from the target server
    while ((nbytes = recv(target_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[nbytes] = '\0'; // Null-terminate the response
        send(client_socket, buffer, nbytes, 0); // Send response back to client
    }

    // Clean up the sockets
    close(target_socket);
    close(client_socket);
}

int main() {
    printf("✨ Welcome to Simple HTTP Proxy Server! ✨\n");

    // Create a socket for the proxy server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address and port
    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any address
    proxy_addr.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Failed to bind socket");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, BACKLOG) < 0) {
        perror("Failed to listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server is up and running on port %d! 📡\n", PORT);
    while (1) {
        // Accept a new connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue; // Keep the server running even if one connection fails
        }

        printf("🎉 Accepted a new connection! 🎉\n");
        handle_request(client_socket);
    }

    // Clean up
    close(server_socket);
    return 0;
}