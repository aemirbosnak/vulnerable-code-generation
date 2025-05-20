//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive client request
    bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(client_socket);
        return;
    }
    buffer[bytes_received] = '\0'; // Null-terminate the buffer

    // Print the received message for logging
    printf("Received request:\n%s\n", buffer);

    // Prepare the HTTP response
    const char *http_response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<html>"
        "<head><title>Simple C Web Server</title></head>"
        "<body><h1>Hello, World!</h1>"
        "<p>This is a simple web server implemented in C.</p>"
        "</body></html>";

    // Send the HTTP response
    send(client_socket, http_response, strlen(http_response), 0);

    // Close the client socket
    close(client_socket);
}

void serve_forever(int server_socket) {
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        
        // Accept incoming connection
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("accept");
            continue; // Skip to the next iteration
        }

        // Handle the client in a separate recursive function
        handle_client(client_socket);
        
        // Recursively call to serve the next client
        serve_forever(server_socket);
    }
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, 10) < 0) {
        perror("listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);
    
    // Start serving clients
    serve_forever(server_socket);

    // Close the server socket (never reached in this example)
    close(server_socket);
    return 0;
}