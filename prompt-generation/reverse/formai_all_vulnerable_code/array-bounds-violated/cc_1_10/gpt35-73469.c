//FormAI DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes;
    bytes = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes <= 0) return;
    buffer[bytes] = '\0';
    printf("Received command: %s\n", buffer);
    if (strncmp(buffer, "GET", 3) == 0) {
        char *msg = "HTTP/1.1 200 OK\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>\r\n";
        send(client_socket, msg, strlen(msg), 0);
    } else if (strncmp(buffer, "POST", 4) == 0) {
        char *msg = "HTTP/1.1 405 Method Not Allowed\r\n\r\n<html><body><h1>Method Not Allowed</h1></body></html>\r\n";
        send(client_socket, msg, strlen(msg), 0);
    } else {
        char *msg = "HTTP/1.1 400 Bad Request\r\n\r\n<html><body><h1>Bad Request</h1></body></html>\r\n";
        send(client_socket, msg, strlen(msg), 0);
    }
}

int main() {
    int server_socket, client_socket, bytes;
    struct sockaddr_in server_address, client_address;
    socklen_t address_length = sizeof(server_address);
    char buffer[BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket to IP address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, address_length) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on http://localhost:%d\n", PORT);

    while (1) {
        // Wait for new connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_length);
        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }

        printf("Client connected: %s\n", inet_ntoa(client_address.sin_addr));

        // Handle client request
        handle_request(client_socket);

        // Close client connection
        close(client_socket);
    }

    // Close server socket
    close(server_socket);

    return 0;
}