//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Read the request from the client
    bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        perror("recv failed");
        close(client_socket);
        return;
    }
    
    buffer[bytes_read] = '\0'; // Null-terminate the buffer

    printf("Received request:\n%s\n", buffer);

    // Simple response message
    const char *http_response = "HTTP/1.1 200 OK\n"
                                "Content-Type: text/html\n"
                                "Connection: close\n\n"
                                "<html><body><h1>Hello, World!</h1>"
                                "<p>This is a simple web server implemented in C.</p>"
                                "</body></html>\n";

    // Send the response to the client
    send(client_socket, http_response, strlen(http_response), 0);
    close(client_socket); // Close the client socket
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create a TCP socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Zero out the server address
    memset(&server_addr, 0, sizeof(server_addr));

    // Set up the server address struct
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to all interfaces
    server_addr.sin_port = htons(PORT); // Set port number

    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) < 0) {
        perror("Listen failed");
        close(server_socket);
        return -1;
    }

    printf("Simple web server is running on port %d...\n", PORT);

    // Main loop to accept incoming connections
    while (1) {
        // Accept a new client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Continue to the next iteration on failure
        }

        // Handle the client in a separate function
        handle_client(client_socket);
    }

    // Close the server socket (not reachable, but good practice)
    close(server_socket);
    return 0;
}