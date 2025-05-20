//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

#define MAX_CLIENT_LINE_SIZE 512
#define MAX_BUFFER_SIZE 4096

int main() {
    int listen_socket, client_socket, bytes_read;
    struct sockaddr_in server_address, client_address;
    struct hostent* server;
    char buffer[MAX_BUFFER_SIZE];
    char request_line[MAX_CLIENT_LINE_SIZE];
    char response[MAX_CLIENT_LINE_SIZE];
    int response_code = 0;

    // Set up the server address structure
    memset((char*) &server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Create a socket for the server
    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the address
    if (bind(listen_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(listen_socket, 5) == -1) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept a connection from a client
        if ((client_socket = accept(listen_socket, (struct sockaddr*) &client_address, (socklen_t*) &bytes_read)) == -1) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        // Read the request line from the client
        bytes_read = recv(client_socket, request_line, MAX_CLIENT_LINE_SIZE - 1, 0);
        request_line[bytes_read] = '\0';

        // Parse the request line to extract the method and URL
        char* method = strtok(request_line, " \t\n");
        char* url = strtok(NULL, " \t\n");

        // Create the response line
        char response_line[MAX_CLIENT_LINE_SIZE];
        snprintf(response_line, MAX_CLIENT_LINE_SIZE, "HTTP/1.1 200 OK\r\n");

        // Set the response code
        if (strcmp(method, "GET") == 0) {
            response_code = 200;
        } else if (strcmp(method, "POST") == 0) {
            response_code = 201;
        } else {
            response_code = 404;
        }

        // Create the response headers
        snprintf(response_line + strlen(response_line), MAX_CLIENT_LINE_SIZE - strlen(response_line), "%s", url);
        snprintf(response_line + strlen(response_line), MAX_CLIENT_LINE_SIZE - strlen(response_line), "Content-Length: %d\r\n", strlen(response_line));
        snprintf(response_line + strlen(response_line), MAX_CLIENT_LINE_SIZE - strlen(response_line), "Content-Type: text/html\r\n");
        snprintf(response_line + strlen(response_line), MAX_CLIENT_LINE_SIZE - strlen(response_line), "\r\n");

        // Send the response headers to the client
        bytes_read = send(client_socket, response_line, strlen(response_line), 0);
        if (bytes_read < 0) {
            perror("Error sending response headers");
            exit(EXIT_FAILURE);
        }

        // Read the request body from the client
        bytes_read = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);

        // Send the response body to the client
        if (strcmp(method, "GET") == 0) {
            snprintf(response_line + strlen(response_line), MAX_CLIENT_LINE_SIZE - strlen(response_line), "Hello, world!\r\n");
        } else {
            snprintf(response_line + strlen(response_line), MAX_CLIENT_LINE_SIZE - strlen(response_line), "Thanks for your POST!\r\n");
        }
        bytes_read = send(client_socket, response_line, strlen(response_line), 0);
        if (bytes_read < 0) {
            perror("Error sending response body");
            exit(EXIT_FAILURE);
        }

        // Close the client socket
        close(client_socket);
    }

    close(listen_socket);

    return 0;
}