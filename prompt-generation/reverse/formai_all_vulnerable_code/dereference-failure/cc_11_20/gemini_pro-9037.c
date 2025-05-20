//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

int main() {
    // Initialize the server socket
    int server_socket;
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept an incoming connection
        int client_socket;
        if ((client_socket = accept(server_socket, NULL, NULL)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Declare a buffer to store the request
        char request[1024];
        memset(request, 0, sizeof(request));

        // Read the request from the client
        int bytes_received = recv(client_socket, request, sizeof(request), 0);
        if (bytes_received < 0) {
            perror("Receive failed");
            close(client_socket);
            continue;
        }

        // Parse the request
        const char *request_line = strtok(request, "\r\n");
        const char *method = strtok(request_line, " ");
        const char *path = strtok(NULL, " ");
        const char *version = strtok(NULL, "\r\n");

        // Check if the request is valid
        if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
            // Send a 400 Bad Request response
            const char *response = "HTTP/1.1 400 Bad Request\r\nContent-Type: text/html\r\n\r\n<html><body><h1>400 Bad Request</h1></body></html>";
            send(client_socket, response, strlen(response), 0);
            close(client_socket);
            continue;
        }

        // Check if the path is valid
        if (strcmp(path, "/") != 0 && strcmp(path, "/index.html") != 0) {
            // Send a 404 Not Found response
            const char *response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>";
            send(client_socket, response, strlen(response), 0);
            close(client_socket);
            continue;
        }

        // Send a 200 OK response
        const char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, world!</h1></body></html>";
        send(client_socket, response, strlen(response), 0);

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}