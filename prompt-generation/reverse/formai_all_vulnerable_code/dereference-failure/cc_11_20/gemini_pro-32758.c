//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: scientific
/*
 * A simple web server that serves static files and handles HTTP requests.
 *
 * This server is not intended to be a complete or secure web server.
 * It is a simple example to demonstrate how to write a basic web server
 * in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 1024

int main(int argc, char** argv) {
    // Check if the correct number of arguments were provided.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the port number from the command line arguments.
    int port = atoi(argv[1]);

    // Create a socket for the server.
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the socket options.
    int reuseaddr_opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr_opt, sizeof(reuseaddr_opt)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Bind the socket to the port.
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections.
    if (listen(server_socket, 10) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Loop forever, accepting and handling connections.
    while (1) {
        // Accept an incoming connection.
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Read the HTTP request from the client.
        char request[MAX_REQUEST_SIZE];
        int bytes_read = read(client_socket, request, MAX_REQUEST_SIZE);
        if (bytes_read == -1) {
            perror("read");
            close(client_socket);
            continue;
        }

        // Parse the HTTP request.
        char* method = strtok(request, " ");
        char* path = strtok(NULL, " ");
        char* version = strtok(NULL, "\r\n");

        // Check if the HTTP request is valid.
        if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
            fprintf(client_socket, "HTTP/1.1 400 Bad Request\r\n\r\n");
            close(client_socket);
            continue;
        }

        // Get the file name from the path.
        char* file_name = path + 1;

        // Open the file.
        FILE* file = fopen(file_name, "r");
        if (file == NULL) {
            fprintf(client_socket, "HTTP/1.1 404 Not Found\r\n\r\n");
            close(client_socket);
            continue;
        }

        // Get the file size.
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        // Set the HTTP response headers.
        fprintf(client_socket, "HTTP/1.1 200 OK\r\n");
        fprintf(client_socket, "Content-Type: text/html\r\n");
        fprintf(client_socket, "Content-Length: %ld\r\n", file_size);
        fprintf(client_socket, "\r\n");

        // Send the file to the client.
        char buffer[1024];
        while (fread(buffer, 1, sizeof(buffer), file) > 0) {
            fwrite(buffer, 1, sizeof(buffer), client_socket);
        }

        // Close the file.
        fclose(file);

        // Close the client socket.
        close(client_socket);
    }

    // Close the server socket.
    close(server_socket);

    return EXIT_SUCCESS;
}