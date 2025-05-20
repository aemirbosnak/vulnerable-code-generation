//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>  // For socket functions
#include <netinet/in.h>  // For sockaddr_in
#include <arpa/inet.h>   // For inet_pton

#define MAX_CONNECTIONS 10

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the port number from the command line
    int port = atoi(argv[1]);

    // Setup the server socket
    int server_socket;
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Couldn't create server socket");
        exit(EXIT_FAILURE);
    }

    // Set the server socket options
    int reuse_addr = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(int)) == -1) {
        perror("Couldn't set server socket options");
        exit(EXIT_FAILURE);
    }

    // Bind the server socket to the port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Couldn't bind server socket to port");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("Couldn't listen for connections");
        exit(EXIT_FAILURE);
    }

    // Accept connections and handle requests
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket;
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) == -1) {
            perror("Couldn't accept connection");
            continue;
        }

        // Handle the request
        char request[1024];
        int bytes_received = recv(client_socket, request, sizeof(request), 0);
        if (bytes_received == -1) {
            perror("Couldn't receive request");
            close(client_socket);
            continue;
        }

        // Parse the request
        char *method = strtok(request, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Check if the request is valid
        if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
            char *error_response = "HTTP/1.1 400 Bad Request\r\n\r\n";
            if (send(client_socket, error_response, strlen(error_response), 0) == -1) {
                perror("Couldn't send error response");
            }
            close(client_socket);
            continue;
        }

        // Get the file from the path
        FILE *file = fopen(path + 1, "r");
        if (file == NULL) {
            char *not_found_response = "HTTP/1.1 404 Not Found\r\n\r\n";
            if (send(client_socket, not_found_response, strlen(not_found_response), 0) == -1) {
                perror("Couldn't send not found response");
            }
            close(client_socket);
            continue;
        }

        // Send the file to the client
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
                perror("Couldn't send file");
                break;
            }
        }
        fclose(file);

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return EXIT_SUCCESS;
}