//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define RESPONSE_OK "HTTP/1.1 200 OK\nContent-Type: text/html\n\n"
#define RESPONSE_NOT_FOUND "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n<h1>404 Not Found</h1>"
#define HTML_CONTENT "<html><body><h1>Welcome to My Simple Web Server!</h1><p>This server is running on C.</p></body></html>"

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        perror("recv failed");
        close(client_socket);
        return;
    }

    buffer[bytes_read] = '\0'; // Null-terminate the buffer
    printf("Received request:\n%s\n", buffer);

    // Check for a simple GET request
    if (strncmp(buffer, "GET / HTTP/1.1", 15) == 0) {
        // Respond with a 200 OK and HTML content
        send(client_socket, RESPONSE_OK, strlen(RESPONSE_OK), 0);
        send(client_socket, HTML_CONTENT, strlen(HTML_CONTENT), 0);
    } else {
        // Respond with 404 Not Found
        send(client_socket, RESPONSE_NOT_FOUND, strlen(RESPONSE_NOT_FOUND), 0);
    }

    // Close the socket
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any address
    server_addr.sin_port = htons(PORT); // Port number

    // Bind the socket to port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
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

    printf("Server is running on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("Accept failed");
            continue; // Don't stop the server, continue listening
        }

        // Handle the client request in a separate method
        handle_client(client_socket);
    }

    // Close the server socket
    close(server_socket);
    return 0;
}