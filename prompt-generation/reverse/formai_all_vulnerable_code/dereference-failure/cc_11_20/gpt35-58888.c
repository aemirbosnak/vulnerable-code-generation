//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 8192

int main(int argc, char **argv) {
    // Check for proper usage
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <listen_port> <destination_ip:destination_port>\n", argv[0]);
        exit(1);
    }

    // Parse the listen port
    int listen_port = atoi(argv[1]);
    if (listen_port <= 0) {
        fprintf(stderr, "Invalid listen port\n");
        exit(1);
    }

    // Parse the destination IP and port
    char *ip_port_str = argv[2];
    char *colon_pos = strchr(ip_port_str, ':');
    if (!colon_pos) {
        fprintf(stderr, "Invalid destination IP and port\n");
        exit(1);
    }
    char *destination_ip_str = strndup(ip_port_str, colon_pos - ip_port_str);
    int destination_port = atoi(colon_pos + 1);
    free(destination_ip_str);
    if (destination_port <= 0) {
        fprintf(stderr, "Invalid destination port\n");
        exit(1);
    }

    // Create a socket to listen for connections
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        fprintf(stderr, "Failed to create listen socket: %s\n", strerror(errno));
        exit(1);
    }

    // Bind the socket to the listen port
    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(listen_port);
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        fprintf(stderr, "Failed to bind listen socket: %s\n", strerror(errno));
        exit(1);
    }

    // Start listening for connections
    if (listen(listen_sock, SOMAXCONN) < 0) {
        fprintf(stderr, "Failed to start listening: %s\n", strerror(errno));
        exit(1);
    }

    // Handle incoming connections
    while (1) {
        // Accept the connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            fprintf(stderr, "Failed to accept connection: %s\n", strerror(errno));
            continue;
        }

        // Read the request from the client
        char request_buffer[MAX_BUFFER_SIZE];
        ssize_t request_size = read(client_sock, request_buffer, MAX_BUFFER_SIZE);
        if (request_size < 0) {
            fprintf(stderr, "Failed to read request: %s\n", strerror(errno));
            close(client_sock);
            continue;
        }

        // Create a socket to connect to the destination
        int destination_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (destination_sock < 0) {
            fprintf(stderr, "Failed to create destination socket: %s\n", strerror(errno));
            close(client_sock);
            continue;
        }

        // Connect to the destination
        struct sockaddr_in destination_addr;
        memset(&destination_addr, 0, sizeof(destination_addr));
        destination_addr.sin_family = AF_INET;
        destination_addr.sin_port = htons(destination_port);
        if (inet_pton(AF_INET, destination_ip_str, &destination_addr.sin_addr) < 0) {
            fprintf(stderr, "Invalid destination IP address\n");
            close(client_sock);
            close(destination_sock);
            continue;
        }
        if (connect(destination_sock, (struct sockaddr *)&destination_addr, sizeof(destination_addr)) < 0) {
            fprintf(stderr, "Failed to connect to destination: %s\n", strerror(errno));
            close(client_sock);
            close(destination_sock);
            continue;
        }

        // Forward the request to the destination
        if (write(destination_sock, request_buffer, request_size) < 0) {
            fprintf(stderr, "Failed to forward request: %s\n", strerror(errno));
            close(client_sock);
            close(destination_sock);
            continue;
        }

        // Read the response from the destination
        char response_buffer[MAX_BUFFER_SIZE];
        ssize_t response_size = read(destination_sock, response_buffer, MAX_BUFFER_SIZE);
        if (response_size < 0) {
            fprintf(stderr, "Failed to read response: %s\n", strerror(errno));
            close(client_sock);
            close(destination_sock);
            continue;
        }

        // Forward the response to the client
        if (write(client_sock, response_buffer, response_size) < 0) {
            fprintf(stderr, "Failed to forward response: %s\n", strerror(errno));
            close(client_sock);
            close(destination_sock);
            continue;
        }

        // Close the sockets
        close(client_sock);
        close(destination_sock);
    }

    return 0;
}