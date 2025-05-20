//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);

    // Create socket for listening
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the given port
    struct sockaddr_in address = {0};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("Failed to bind to port");
        exit(EXIT_FAILURE);
    }

    // Start listening on the socket
    if (listen(server_fd, 5) == -1) {
        perror("Failed to start listening");
        exit(EXIT_FAILURE);
    }

    printf("HTTP proxy listening on port %d\n", port);

    while (1) {
        // Accept incoming connection
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("Failed to accept connection");
            continue;
        }

        char buffer[BUFFER_SIZE] = {0};
        int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);

        if (bytes_received == -1) {
            perror("Failed to receive data");
            continue;
        }

        char *request = strtok(buffer, "\n");
        char *url = strtok(request, " ");
        url = strtok(NULL, " ");

        // Parse out the host and port from the URL
        char *host = strstr(url, "://");
        if (host == NULL) {
            fprintf(stderr, "Invalid URL: %s\n", url);
            close(client_fd);
            continue;
        }

        host += 3;
        char *path = strchr(host, '/');
        if (path == NULL) {
            fprintf(stderr, "Invalid path: %s\n", url);
            close(client_fd);
            continue;
        }

        *path = '\0';
        path++;

        char *port_str = strchr(host, ':');
        if (port_str != NULL) {
            *port_str = '\0';
            port_str++;
        } else {
            port_str = "80";
        }

        // Create a new socket to the remote server
        int remote_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_fd == -1) {
            perror("Failed to create socket");
            close(client_fd);
            continue;
        }

        struct sockaddr_in remote_address = {0};
        remote_address.sin_family = AF_INET;
        remote_address.sin_addr.s_addr = inet_addr(host);
        remote_address.sin_port = htons(atoi(port_str));

        // Connect to the remote server
        if (connect(remote_fd, (struct sockaddr *)&remote_address, sizeof(remote_address)) == -1) {
            perror("Failed to connect to remote server");
            close(client_fd);
            close(remote_fd);
            continue;
        }

        // Forward the request to the remote server
        if (send(remote_fd, request, strlen(request), 0) == -1) {
            perror("Failed to send data to remote server");
            close(client_fd);
            close(remote_fd);
            continue;
        }

        // Forward the response from the remote server to the client
        while ((bytes_received = recv(remote_fd, buffer, BUFFER_SIZE, 0)) > 0) {
            if (send(client_fd, buffer, bytes_received, 0) == -1) {
                perror("Failed to send data to client");
                close(client_fd);
                close(remote_fd);
                break;
            }
        }

        close(client_fd);
        close(remote_fd);
    }

    return 0;
}