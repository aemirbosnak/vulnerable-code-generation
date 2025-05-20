//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_request(int client_socket);
void forward_request(int client_socket, char *buffer, size_t n);
void send_response(int client_socket, char *response, size_t response_length);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_len = sizeof(client_address);
    
    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Bind the socket
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
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
    
    printf("Listening on port %d...\n", PORT);
    
    while (1) {
        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        
        // Handle the request
        handle_request(client_socket);
        
        // Close the client socket
        close(client_socket);
    }
    
    close(server_socket);
    return 0;
}

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Error receiving data");
        return;
    }
    
    buffer[bytes_received] = '\0'; // Null terminate the received data
    
    // Print the received HTTP request
    printf("Received request:\n%s\n", buffer);
    
    // Forward the request to the target server
    forward_request(client_socket, buffer, bytes_received);
}

void forward_request(int client_socket, char *buffer, size_t n) {
    char method[10], url[256], http_version[10];
    char host[100];
    int port = 80;
    
    // Parse the HTTP request
    sscanf(buffer, "%s %s %s", method, url, http_version);
    
    // Extract host and port if specified
    char *host_start = strstr(buffer, "Host: ");
    if (host_start) {
        host_start += 6; // Skip "Host: "
        sscanf(host_start, "%s", host);
        char *port_pos = strchr(host, ':');
        if (port_pos) {
            port = atoi(port_pos + 1);
            *port_pos = '\0'; // Remove the port from the host string
        }
    }
    
    // Connect to the target server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return;
    }
    
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    
    if (inet_pton(AF_INET, host, &server_address.sin_addr) <= 0) {
        perror("Invalid address");
        close(server_socket);
        return;
    }
    
    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to server failed");
        close(server_socket);
        return;
    }
    
    // Send the original HTTP request to the target server
    send(server_socket, buffer, n, 0);
    
    // Receive and forward the response back to the client
    char response[BUFFER_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(server_socket, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null terminate the received response
        send_response(client_socket, response, bytes_received);
    }
    
    // Close the server socket
    close(server_socket);
}

void send_response(int client_socket, char *response, size_t response_length) {
    // Send the response to the client
    send(client_socket, response, response_length, 0);
}