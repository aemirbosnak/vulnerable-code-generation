//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_REQUEST_SIZE 4096
#define MAX_RESPONSE_SIZE 8192

struct proxy_connection {
    int client_fd;
    int server_fd;
    char request[MAX_REQUEST_SIZE];
    char response[MAX_RESPONSE_SIZE];
    size_t request_size;
    size_t response_size;
};

void handle_client(struct proxy_connection *connection) {
    // Read the request from the client.
    ssize_t bytes_read = read(connection->client_fd, connection->request, MAX_REQUEST_SIZE);
    if (bytes_read == -1) {
        perror("read");
        close(connection->client_fd);
        return;
    }
    connection->request_size = bytes_read;

    // Parse the request.
    char *host = strstr(connection->request, "Host: ");
    if (host == NULL) {
        fprintf(stderr, "Invalid request: missing Host header\n");
        close(connection->client_fd);
        return;
    }
    host += strlen("Host: ");
    char *port = strchr(host, ':');
    if (port == NULL) {
        port = "80";
    } else {
        *port++ = '\0';
    }

    // Connect to the server.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) != 1) {
        fprintf(stderr, "Invalid host: %s\n", host);
        close(connection->client_fd);
        return;
    }
    connection->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (connection->server_fd == -1) {
        perror("socket");
        close(connection->client_fd);
        return;
    }
    if (connect(connection->server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(connection->client_fd);
        close(connection->server_fd);
        return;
    }

    // Send the request to the server.
    ssize_t bytes_sent = write(connection->server_fd, connection->request, connection->request_size);
    if (bytes_sent == -1) {
        perror("write");
        close(connection->client_fd);
        close(connection->server_fd);
        return;
    }

    // Read the response from the server.
    bytes_read = read(connection->server_fd, connection->response, MAX_RESPONSE_SIZE);
    if (bytes_read == -1) {
        perror("read");
        close(connection->client_fd);
        close(connection->server_fd);
        return;
    }
    connection->response_size = bytes_read;

    // Send the response to the client.
    bytes_sent = write(connection->client_fd, connection->response, connection->response_size);
    if (bytes_sent == -1) {
        perror("write");
        close(connection->client_fd);
        close(connection->server_fd);
        return;
    }

    // Close the connections.
    close(connection->client_fd);
    close(connection->server_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create a listening socket.
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        return 1;
    }

    // Set the listening socket to non-blocking mode.
    int flags = fcntl(listen_fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        close(listen_fd);
        return 1;
    }
    if (fcntl(listen_fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl");
        close(listen_fd);
        return 1;
    }

    // Bind the listening socket to the specified port.
    struct sockaddr_in listen_addr;
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        close(listen_fd);
        return 1;
    }

    // Start listening for connections.
    if (listen(listen_fd, SOMAXCONN) == -1) {
        perror("listen");
        close(listen_fd);
        return 1;
    }

    // Main loop.
    while (1) {
        // Accept a new connection.
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                // No new connections, continue.
                continue;
            } else {
                perror("accept");
                close(listen_fd);
                return 1;
            }
        }

        // Set the client socket to non-blocking mode.
        flags = fcntl(client_fd, F_GETFL, 0);
        if (flags == -1) {
            perror("fcntl");
            close(client_fd);
            continue;
        }
        if (fcntl(client_fd, F_SETFL, flags | O_NONBLOCK) == -1) {
            perror("fcntl");
            close(client_fd);
            continue;
        }

        // Create a new proxy connection.
        struct proxy_connection *connection = malloc(sizeof(struct proxy_connection));
        if (connection == NULL) {
            perror("malloc");
            close(client_fd);
            continue;
        }
        connection->client_fd = client_fd;
        connection->server_fd = -1;
        connection->request_size = 0;
        connection->response_size = 0;

        // Handle the client connection.
        handle_client(connection);

        // Free the proxy connection.
        free(connection);
    }

    // Close the listening socket.
    close(listen_fd);

    return 0;
}