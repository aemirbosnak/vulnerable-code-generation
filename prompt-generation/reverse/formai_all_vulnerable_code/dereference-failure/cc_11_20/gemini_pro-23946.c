//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

// Define the port number for the server
#define PORT 8080

int main() {
    // Create a socket for the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        return -1;
    }

    // Bind the socket to the port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) < 0) {
        perror("Error listening for connections");
        return -1;
    }

    // Accept connections from clients
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);
        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Handle the client request
        char buffer[1024];
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received < 0) {
            perror("Error receiving request");
            close(client_socket);
            continue;
        }

        // Parse the request
        char *request_line = strtok(buffer, "\r\n");
        char *method = strtok(request_line, " ");
        char *path = strtok(NULL, " ");
        char *http_version = strtok(NULL, "\r");

        // Send the response
        char response[1024];
        if (strcmp(method, "GET") == 0) {
            // Handle GET requests
            int file_descriptor = open(path, O_RDONLY);
            if (file_descriptor < 0) {
                // File not found
                sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\nFile not found");
            } else {
                // File found
                char file_content[1024];
                int bytes_read = read(file_descriptor, file_content, sizeof(file_content));
                if (bytes_read < 0) {
                    // Error reading file
                    sprintf(response, "HTTP/1.1 500 Internal Server Error\r\nContent-Type: text/plain\r\n\r\nError reading file");
                } else {
                    // Success
                    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n%s", file_content);
                }
                close(file_descriptor);
            }
        } else {
            // Handle other methods
            sprintf(response, "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/plain\r\n\r\nMethod not allowed");
        }

        // Send the response to the client
        if (send(client_socket, response, strlen(response), 0) < 0) {
            perror("Error sending response");
        }

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}