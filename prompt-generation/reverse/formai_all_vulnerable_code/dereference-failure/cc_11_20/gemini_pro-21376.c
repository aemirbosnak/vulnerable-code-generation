//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

// This program is an example of a very simple web server.
// It listens on a specified port and serves static files.

// The main function.
int main(int argc, char *argv[]) {
    // Check that the user has provided a port number.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port_number\n", argv[0]);
        return 1;
    }

    // Get the port number from the user.
    int port_number = atoi(argv[1]);

    // Create a socket.
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return 1;
    }

    // Set the socket to non-blocking mode.
    int flags = fcntl(server_socket, F_GETFL, 0);
    if (flags < 0) {
        perror("fcntl");
        return 1;
    }
    if (fcntl(server_socket, F_SETFL, flags | O_NONBLOCK) < 0) {
        perror("fcntl");
        return 1;
    }

    // Bind the socket to the port number.
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections.
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections.
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Read the request from the client.
        char request[1024];
        int request_length = read(client_socket, request, sizeof(request) - 1);
        if (request_length < 0) {
            perror("read");
            close(client_socket);
            continue;
        }
        request[request_length] = '\0';

        // Parse the request.
        char *method = strtok(request, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Check that the request is valid.
        if (strcmp(method, "GET") != 0) {
            // The request is not a GET request.
            char *error_message = "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/plain\r\nContent-Length: 0\r\n\r\n";
            write(client_socket, error_message, strlen(error_message));
            close(client_socket);
            continue;
        }

        if (strcmp(version, "HTTP/1.1") != 0) {
            // The request is not an HTTP/1.1 request.
            char *error_message = "HTTP/1.1 400 Bad Request\r\nContent-Type: text/plain\r\nContent-Length: 0\r\n\r\n";
            write(client_socket, error_message, strlen(error_message));
            close(client_socket);
            continue;
        }

        // Open the file that the client is requesting.
        int file_descriptor = open(path + 1, O_RDONLY);
        if (file_descriptor < 0) {
            // The file could not be opened.
            char *error_message = "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\nContent-Length: 0\r\n\r\n";
            write(client_socket, error_message, strlen(error_message));
            close(client_socket);
            continue;
        }

        // Read the file into a buffer.
        char buffer[1024];
        int bytes_read;
        while ((bytes_read = read(file_descriptor, buffer, sizeof(buffer))) > 0) {
            // Write the buffer to the client.
            write(client_socket, buffer, bytes_read);
        }

        // Close the file.
        close(file_descriptor);

        // Close the client socket.
        close(client_socket);
    }

    // Close the server socket.
    close(server_socket);

    return 0;
}