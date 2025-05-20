//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;
    char buffer[BUFFER_SIZE];
    int bytes_received, bytes_sent;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8080);

    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections
    while (1) {
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Receive the HTTP request from the client
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received == -1) {
            perror("recv");
            close(client_socket);
            continue;
        }

        buffer[bytes_received] = '\0';

        // Parse the HTTP request
        char *method = strtok(buffer, " ");
        char *path = strtok(NULL, " ");
        char *protocol = strtok(NULL, "\r\n");

        // Send the HTTP response to the client
        char response[BUFFER_SIZE];
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", strlen(buffer));
        bytes_sent = send(client_socket, response, strlen(response), 0);
        if (bytes_sent == -1) {
            perror("send");
            close(client_socket);
            continue;
        }

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}