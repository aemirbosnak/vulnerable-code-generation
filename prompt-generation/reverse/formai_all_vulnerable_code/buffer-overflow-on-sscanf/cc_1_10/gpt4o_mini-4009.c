//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8888
#define BUFFER_SIZE 4096

void handle_client(int client_socket);
void forward_request(int client_socket, const char *hostname, int port, const char *request);

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

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("HTTP Proxy Server is running on port %d\n", PORT);

    while (1) {
        // Accept a client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accepting connection failed");
            continue; // Continue accepting other connections
        }

        handle_client(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int received_size = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (received_size < 0) {
        perror("Receiving failed");
        return;
    }

    buffer[received_size] = '\0'; // Null-terminate the received data
    printf("Received request:\n%s\n", buffer);

    // Parse the request to find the host and port
    char method[10], path[256], version[10], hostname[256];
    int port = 80;

    sscanf(buffer, "%s %s %s", method, path, version);
    char *host_start = strstr(buffer, "Host: ");
    if (host_start) {
        host_start += 6; // Move past "Host: "
        char *host_end = strstr(host_start, "\r\n");
        if (host_end) {
            *host_end = '\0'; // Null terminate the host string
            strncpy(hostname, host_start, sizeof(hostname) - 1);
            hostname[sizeof(hostname) - 1] = '\0'; // Ensure null-termination
            
            // Check for port in hostname
            char *colon = strchr(hostname, ':');
            if (colon) {
                *colon = '\0';
                port = atoi(colon + 1); // Get port if specified
            }
        }
    } else {
        fprintf(stderr, "Host header not found\n");
        return;
    }

    forward_request(client_socket, hostname, port, buffer);
}

void forward_request(int client_socket, const char *hostname, int port, const char *request) {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create a socket for the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation for server failed");
        return;
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname); // Convert hostname to IP address

    // Connect to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_socket);
        return;
    }

    // Forward the request to the actual server
    send(server_socket, request, strlen(request), 0);
    
    // Receive the response from the server
    char response[BUFFER_SIZE];
    int bytes_received;
    
    while ((bytes_received = recv(server_socket, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        send(client_socket, response, bytes_received, 0); // Send response back to client
    }

    if (bytes_received < 0) {
        perror("Receiving response from server failed");
    }

    close(server_socket); // Close the server socket
}