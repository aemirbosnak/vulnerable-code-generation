//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {

    printf("Starting up the proxy server on port %d. Get ready to have some fun!\n", PORT);

    // Create a listening socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        error("socket");
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("bind");
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        error("listen");
    }

    // Loop forever, accepting connections and forwarding them
    while (1) {

        // Accept a connection from a client
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            error("accept");
        }

        char request[1024];
        memset(request, 0, sizeof(request));

        // Read the request from the client
        int bytes_read = read(client_fd, request, sizeof(request) - 1);
        if (bytes_read < 0) {
            error("read");
        }

        // Parse the request to get the host, port, and path
        char *host = NULL;
        char *port = NULL;
        char *path = NULL;
        if (sscanf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host) != 3) {
            error("sscanf");
        }

        printf("Received a request for %s from %s.\n", path, host);

        // Connect to the destination server
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0) {
            error("socket");
        }

        struct sockaddr_in server_socket_addr;
        server_socket_addr.sin_family = AF_INET;
        server_socket_addr.sin_port = htons(atoi(port));
        server_socket_addr.sin_addr.s_addr = inet_addr(host);

        if (connect(server_socket, (struct sockaddr *)&server_socket_addr, sizeof(server_socket_addr)) < 0) {
            error("connect");
        }

        // Forward the request to the destination server
        if (write(server_socket, request, strlen(request)) < 0) {
            error("write");
        }

        // Read the response from the destination server
        char response[1024];
        memset(response, 0, sizeof(response));
        int bytes_received = read(server_socket, response, sizeof(response) - 1);
        if (bytes_received < 0) {
            error("read");
        }

        // Forward the response to the client
        if (write(client_fd, response, strlen(response)) < 0) {
            error("write");
        }

        // Close the connection with the client
        close(client_fd);

        // Close the connection with the destination server
        close(server_socket);
    }

    // Close the listening socket
    close(server_fd);

    return 0;
}