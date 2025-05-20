//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    // Read request from the client
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to read from client");
        close(client_socket);
        return;
    }

    // Print the request (for logging purposes)
    printf("Received request:\n%s\n", buffer);

    // Extract the first line of the request to get the host and path
    char method[10], host[100], path[100];
    sscanf(buffer, "%s http://%99[^/]/%99s", method, host, path);

    // Open a socket to the target host
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Placeholder, typically resolve the hostname.

    // Connect to the target host server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Forward the client request to the target server
    char request[BUFFER_SIZE];
    sprintf(request, "%s /%s HTTP/1.0\r\nHost: %s\r\n\r\n", method, path, host);
    send(server_socket, request, strlen(request), 0);

    // Read the response from the server
    while ((bytes_received = recv(server_socket, buffer, sizeof(buffer), 0)) > 0) {
        // Send the response back to the client
        send(client_socket, buffer, bytes_received, 0);
    }

    // Clean up sockets
    close(server_socket);
    close(client_socket);
}

int main() {
    int proxy_socket, client_socket;
    struct sockaddr_in proxy_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create a socket for the proxy
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Bind failed");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(proxy_socket, 5) < 0) {
        perror("Listen failed");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    printf("Futuristic HTTP Proxy running on port %d...\n", PORT);

    while (1) {
        // Accept a client connection
        client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Handle the client request in a new "futuristic" thread (for simplicity, it's sequential in this version)
        handle_client(client_socket);
    }

    // Close the proxy socket (though this code will never reach here)
    close(proxy_socket);
    return 0;
}