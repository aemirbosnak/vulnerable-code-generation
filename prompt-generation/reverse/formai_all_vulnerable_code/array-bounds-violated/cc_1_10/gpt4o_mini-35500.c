//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define BACKLOG 10

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void cleanup(int sockfd) {
    if (sockfd >= 0) {
        close(sockfd);
    }
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        handle_error("socket");
    }

    // Setting up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        cleanup(server_fd);
        handle_error("bind");
    }

    // Listening for incoming connections
    if (listen(server_fd, BACKLOG) == -1) {
        cleanup(server_fd);
        handle_error("listen");
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        // Accepting a connection from the client
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len)) == -1) {
            fprintf(stderr, "accept error: %s\n", strerror(errno));
            continue;  // Continue to the next iteration to accept new connections
        }

        printf("Client connected.\n");

        // Receiving messages from the client
        ssize_t bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received < 0) {
            fprintf(stderr, "recv error: %s\n", strerror(errno));
            cleanup(client_fd);
            continue;  // Continue to accept next connections
        } else if (bytes_received == 0) {
            printf("Client disconnected unexpectedly.\n");
            cleanup(client_fd);
            continue;  // Client has disconnected
        }

        // Null-terminate the received data to make it a string
        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);

        // Echoing the message back to the client
        ssize_t bytes_sent = send(client_fd, buffer, bytes_received, 0);
        if (bytes_sent < 0) {
            fprintf(stderr, "send error: %s\n", strerror(errno));
        } else {
            printf("Echoed back %zd bytes to the client.\n", bytes_sent);
        }

        // Closing the client socket
        cleanup(client_fd);
        printf("Client connection closed.\n");
    }

    // Cleanup and close the server socket (note: unreachable code in this example)
    cleanup(server_fd);
    return 0;
}