//FormAI DATASET v1.0 Category: Simple Web Server ; Style: scientific
// C Simple Web Server

// This program creates a simple web server that responds to HTTP GET requests
// The server listens on a specified port for incoming requests
// When a request is received, the server checks if the requested file exists on the server
// If the file exists, it is sent to the client, otherwise a 404 Not Found error is sent

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

// Function prototypes
void handle_client(int client_socket);

int main(int argc, char **argv)
{
    // Handle command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Set socket options to allow reuse of address and port
    int optval = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("Failed to set socket options");
        exit(1);
    }

    // Bind socket to the specified address and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, SOMAXCONN) < 0) {
        perror("Failed to listen for connections");
        exit(1);
    }

    // Wait for incoming connections
    for (;;) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue;
        }

        handle_client(client_socket);

        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}

void handle_client(int client_socket)
{
    // Read the HTTP request from the client
    char buffer[BUF_SIZE];
    ssize_t bytes_read = recv(client_socket, buffer, BUF_SIZE, 0);
    if (bytes_read < 0) {
        perror("Failed to read from client");
        return;
    }

    // Parse the HTTP request
    char method[BUF_SIZE], path[BUF_SIZE], protocol[BUF_SIZE];
    if (sscanf(buffer, "%s %s %s", method, path, protocol) != 3) {
        send(client_socket, "HTTP/1.1 400 Bad Request\r\n", strlen("HTTP/1.1 400 Bad Request\r\n"), 0);
        return;
    }

    // Check that the request method is GET
    if (strcasecmp(method, "GET") != 0) {
        send(client_socket, "HTTP/1.1 501 Not Implemented\r\n", strlen("HTTP/1.1 501 Not Implemented\r\n"), 0);
        return;
    }

    // Open the requested file
    int file_fd = open(path, O_RDONLY);
    if (file_fd < 0) {
        send(client_socket, "HTTP/1.1 404 Not Found\r\n", strlen("HTTP/1.1 404 Not Found\r\n"), 0);
        return;
    }

    // Send the file to the client
    char response[BUF_SIZE];
    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", (int)lseek(file_fd, 0, SEEK_END));
    send(client_socket, response, strlen(response), 0);
    lseek(file_fd, 0, SEEK_SET);
    for (;;) {
        bytes_read = read(file_fd, buffer, BUF_SIZE);
        if (bytes_read <= 0) break;
        send(client_socket, buffer, bytes_read, 0);
    }

    // Close the file
    close(file_fd);
}