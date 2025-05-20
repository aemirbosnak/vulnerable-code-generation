//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define BACKLOG 10

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int received_bytes;
  
    // Receive HTTP request
    received_bytes = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
    if (received_bytes < 0) {
        perror("Failed to receive request");
        close(client_sock);
        return;
    }

    buffer[received_bytes] = '\0'; // Null-terminate the received data

    // Log the received request (for debugging purposes)
    printf("Received request:\n%s\n", buffer);

    // Prepare HTTP response
    char *http_response = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 66\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<html><body><h1>Hello, World!</h1></body></html>";

    // Send response to the client
    send(client_sock, http_response, strlen(http_response), 0);

    // Close the client socket
    close(client_sock);
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create the socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, BACKLOG) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Main server loop
    while (1) {
        // Accept a client connection
        if ((client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_len)) < 0) {
            perror("Accept failed");
            continue; // Go to the next iteration
        }

        // Fork a process to handle the client
        if (fork() == 0) {
            // In child process
            close(server_sock); // Child doesn't need the main server socket
            handle_client(client_sock);
            exit(EXIT_SUCCESS); // Terminate child process
        }
        
        // In parent process
        close(client_sock); // Parent doesn't need this socket
    }

    // Close the server socket (unreachable in this code, but good practice)
    close(server_sock);
    return 0;
}