//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080 // Port to listen on

// Function to send an HTTP response to the client
void send_response(int client_fd, char *response) {
    // Get the length of the response
    size_t response_len = strlen(response);

    // Send the response header
    char header[256];
    sprintf(header, "HTTP/1.1 200 OK\r\nContent-Length: %zu\r\n\r\n", response_len);
    send(client_fd, header, strlen(header), 0);

    // Send the response body
    send(client_fd, response, response_len, 0);
}

// Function to handle a client connection
void handle_client(int client_fd) {
    // Buffer to store the client request
    char request[1024];

    // Read the client request
    recv(client_fd, request, sizeof(request), 0);

    // Parse the request and get the requested path
    char path[256];
    sscanf(request, "GET %s HTTP/1.1", path);

    // Check if the path is valid
    if (strcmp(path, "/") == 0) {
        // Send the index page
        send_response(client_fd, "<h1>Hello from the Simple Web Server!</h1>");
    } else {
        // Send a 404 error
        send_response(client_fd, "<h1>404 Not Found</h1>");
    }

    // Close the client connection
    close(client_fd);
}

int main() {
    // Create a listening socket
    int listening_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_fd == -1) {
        perror("Error creating listening socket");
        exit(1);
    }

    // Bind the socket to the specified port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listening_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket to port");
        exit(1);
    }

    // Start listening for incoming connections
    if (listen(listening_fd, 10) == -1) {
        perror("Error listening for connections");
        exit(1);
    }

    // Main loop: accept and handle client connections
    while (1) {
        // Accept an incoming connection
        int client_fd = accept(listening_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("Error accepting client connection");
            continue;
        }

        // Handle the client connection in a separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *(*)(void *))handle_client, (void *)client_fd);
    }

    // Close the listening socket
    close(listening_fd);

    return 0;
}