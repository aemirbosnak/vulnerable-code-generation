//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define PORT 8080

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int bytes_read = recv(client_sock, buffer, BUFFER_SIZE, 0);
    
    if (bytes_read < 0) {
        perror("Failed to read from client");
        close(client_sock);
        return;
    }
    
    buffer[bytes_read] = '\0'; // Null-terminate the buffer

    // Parse the request
    char method[10], url[256], http_version[10];
    sscanf(buffer, "%s %s %s", method, url, http_version);

    // Parse the host and port (default to 80 if not specified)
    char host[256];
    int port = 80;
    char *host_start = strstr(url, "://");
    if (host_start) {
        host_start += 3; // Skip "://"
    } else {
        host_start = url;
    }

    char *host_end = strchr(host_start, '/');
    if (host_end) {
        strncpy(host, host_start, host_end - host_start);
        host[host_end - host_start] = '\0';
    } else {
        strcpy(host, host_start);
    }

    char *port_start = strchr(host, ':');
    if (port_start) {
        port = atoi(port_start + 1);
        *port_start = '\0'; // Null terminate to isolate host
    }

    // Create a socket to the remote server
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Failed to create socket");
        close(client_sock);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Using localhost for demo purposes (change accordingly)

    // Connect to the server
    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        close(client_sock);
        close(server_sock);
        return;
    }

    // Forward the request to the remote server
    send(server_sock, buffer, bytes_read, 0);

    // Receive the response from the remote server
    while ((bytes_read = recv(server_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_sock, buffer, bytes_read, 0); // Send response back to client
    }

    // Close the sockets
    close(server_sock);
    close(client_sock);
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Failed to create socket");
        return EXIT_FAILURE;
    }

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on any address
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_sock);
        return EXIT_FAILURE;
    }

    // Start listening for connections
    if (listen(server_sock, 5) < 0) {
        perror("Listening failed");
        close(server_sock);
        return EXIT_FAILURE;
    }

    printf("Proxy server running on port %d\n", PORT);

    // Accept connections and handle clients
    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Failed to accept connection");
            continue; // Go to next iteration
        }

        handle_client(client_sock);
    }

    // Close the main server socket (not reached in this demo)
    close(server_sock);
    return EXIT_SUCCESS;
}