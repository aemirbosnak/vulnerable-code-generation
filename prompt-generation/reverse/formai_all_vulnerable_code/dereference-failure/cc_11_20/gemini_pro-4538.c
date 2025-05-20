//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: inquisitive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096
#define MAX_REQ_LINE_LEN 8192

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments was provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source-port> <destination-host:port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the source port and destination host:port
    int source_port = atoi(argv[1]);
    char *destination_host = strtok(argv[2], ":");
    int destination_port = atoi(strtok(NULL, ":"));

    // Create a socket for listening on the source port
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the sockaddr_in structure for the listening socket
    struct sockaddr_in listening_addr;
    memset(&listening_addr, 0, sizeof(struct sockaddr_in));
    listening_addr.sin_family = AF_INET;
    listening_addr.sin_addr.s_addr = INADDR_ANY;
    listening_addr.sin_port = htons(source_port);

    // Bind the listening socket to the source port
    if (bind(listening_socket, (struct sockaddr *) &listening_addr, sizeof(listening_addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Set the listening socket to listen for incoming connections
    if (listen(listening_socket, 5) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections and forward requests to the destination host:port
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        // Accept an incoming connection
        int client_socket = accept(listening_socket, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Read the HTTP request line from the client
        char request_line[MAX_REQ_LINE_LEN];
        int bytes_read = read(client_socket, request_line, MAX_REQ_LINE_LEN - 1);
        if (bytes_read < 0) {
            perror("read");
            close(client_socket);
            continue;
        }
        request_line[bytes_read] = '\0';

        // Parse the HTTP request line
        char *method = strtok(request_line, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Print the HTTP request line to the console
        printf("Received request: %s %s %s\n", method, path, version);

        // Create a socket for connecting to the destination host:port
        int destination_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (destination_socket < 0) {
            perror("socket");
            close(client_socket);
            continue;
        }

        // Set up the sockaddr_in structure for the destination host:port
        struct sockaddr_in destination_addr;
        memset(&destination_addr, 0, sizeof(struct sockaddr_in));
        destination_addr.sin_family = AF_INET;
        destination_addr.sin_addr.s_addr = inet_addr(destination_host);
        destination_addr.sin_port = htons(destination_port);

        // Connect to the destination host:port
        if (connect(destination_socket, (struct sockaddr *) &destination_addr, sizeof(destination_addr)) < 0) {
            perror("connect");
            close(client_socket);
            close(destination_socket);
            continue;
        }

        // Forward the HTTP request to the destination host:port
        if (write(destination_socket, request_line, strlen(request_line)) < 0) {
            perror("write");
            close(client_socket);
            close(destination_socket);
            continue;
        }

        // Read the HTTP response from the destination host:port
        char response[BUF_SIZE];
        int bytes_received = read(destination_socket, response, BUF_SIZE - 1);
        if (bytes_received < 0) {
            perror("read");
            close(client_socket);
            close(destination_socket);
            continue;
        }
        response[bytes_received] = '\0';

        // Print the HTTP response to the console
        printf("Received response: %s", response);

        // Forward the HTTP response to the client
        if (write(client_socket, response, strlen(response)) < 0) {
            perror("write");
            close(client_socket);
            close(destination_socket);
            continue;
        }

        // Close the client and destination sockets
        close(client_socket);
        close(destination_socket);
    }

    // Close the listening socket
    close(listening_socket);

    return EXIT_SUCCESS;
}