//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

// Function to handle the request and send the response
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes_received < 0) {
        perror("recv");
        close(client_socket);
        return;
    }
    
    buffer[bytes_received] = '\0'; // Null-terminate the received data

    // Log the received request
    printf("Received request:\n%s\n", buffer);
    
    // Prepare the response
    char *response_header = "HTTP/1.1 200 OK\r\n"
                            "Content-Type: text/html\r\n"
                            "Connection: close\r\n\r\n";
    
    char *response_body = "<html><body><h1>Welcome to the Simple Web Server!</h1><p>This is a basic static response.</p></body></html>";
    
    // Send the header and body to the client
    send(client_socket, response_header, strlen(response_header), 0);
    send(client_socket, response_body, strlen(response_body), 0);
    
    // Close the client socket
    close(client_socket);
}

// Main function
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // Create the socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on any interface
    server_addr.sin_port = htons(PORT); // Convert port number to network byte order

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, BACKLOG) == -1) {
        perror("listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // Main loop to accept and handle client connections
    while (1) {
        // Accept a client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Handle the client request in a separate function
        handle_client(client_socket);
    }

    // Close the server socket
    close(server_socket);
    return 0;
}