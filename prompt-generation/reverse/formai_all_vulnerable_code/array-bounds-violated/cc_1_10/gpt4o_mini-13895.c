//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8888
#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char *http_request = NULL;
    size_t request_size = 0;
    
    // Receive HTTP Request from Client
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        close(client_socket);
        return;
    }
    buffer[bytes_received] = '\0';
    
    printf("Received Request:\n%s\n", buffer);
    
    // Parse the request for the destination host
    char *host = NULL;
    char *port_str = "80";

    // Extract Host from HTTP headers
    char *line = strtok(buffer, "\r\n");
    if (line) {
        line = strtok(NULL, "\r\n"); // Skip the first line
        while (line) {
            if (strncmp(line, "Host:", 5) == 0) {
                host = line + 6; // Move past "Host: "
                char *end = strchr(host, ':');
                if (end) {
                    *end = '\0';
                    port_str = end + 1; // Save port if specified
                }
                break;
            }
            line = strtok(NULL, "\r\n");
        }
    }

    if (!host) {
        fprintf(stderr, "Host not found in request\n");
        close(client_socket);
        return;
    }

    // Create a socket to the destination server
    int server_socket;
    struct sockaddr_in server_addr;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        close(client_socket);
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port_str));
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // Connect to the server
    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Forward the request to the destination server
    send(server_socket, buffer, bytes_received, 0);

    // Receive response from the server
    while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate for safety
        send(client_socket, buffer, bytes_received, 0); // Send response back to client
    }

    // Clean up
    close(server_socket);
    close(client_socket);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Define server properties
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to all interfaces
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Failed to accept client connection");
            continue;
        }
        printf("Accepted connection from client.\n");

        // Handle client socket in a separate function
        handle_client(client_socket);
    }

    // Close the server socket (unreachable code)
    close(server_socket);
    return 0;
}