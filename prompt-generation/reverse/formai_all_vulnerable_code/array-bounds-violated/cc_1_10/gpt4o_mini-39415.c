//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 4096

// Function to handle client requests
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes_read < 0) {
        perror("Failed to read from socket");
        return;
    }

    buffer[bytes_read] = '\0'; // Null-terminate the buffer
    printf("Received request:\n%s\n", buffer);

    // Crafting the response
    char response[BUFFER_SIZE];
    sprintf(response, "HTTP/1.1 200 OK\r\n"
                      "Content-Type: text/html\r\n"
                      "Connection: close\r\n"
                      "\r\n"
                      "<html>"
                      "<head><title>Welcome to C Web Server!</title></head>"
                      "<body>"
                      "<h1>Welcome!</h1>"
                      "<p>This is a whimsical C web server!</p>"
                      "<p>Why did the programmer quit his job?</p>"
                      "<p>Because he didn't get arrays!</p>"
                      "<p>Thanks for visiting!</p>"
                      "</body>"
                      "</html>");

    // Send the response
    send(client_socket, response, strlen(response), 0);
    
    // Close the socket
    close(client_socket);
}

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, BACKLOG) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Simple Web Server is running on http://127.0.0.1:%d\n", PORT);
    
    while (1) {
        // Accept a client connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Handle the client request
        handle_client(client_socket);
    }

    // Cleanup is never reached, but good practice nonetheless
    close(server_socket);
    return 0;
}