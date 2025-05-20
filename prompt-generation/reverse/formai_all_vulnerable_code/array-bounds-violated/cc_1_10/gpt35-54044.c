//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80 // HTTP port
#define BUFFER_SIZE 4096 // Maximum HTTP response size

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* url = argv[1];
    char* hostname;
    char* path;
    int socket_fd;
    struct addrinfo hints;
    struct addrinfo* result;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    ssize_t bytes_received;

    // Parse URL to get hostname and path
    if (sscanf(url, "http://%m[^/]/%ms", &hostname, &path) != 2) {
        fprintf(stderr, "Invalid URL: %s\n", url);
        return EXIT_FAILURE;
    }

    // Initialize socket hints
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Resolve hostname to IP address
    if (getaddrinfo(hostname, "http", &hints, &result) != 0) {
        fprintf(stderr, "Failed to resolve hostname %s: %s\n", hostname, strerror(errno));
        return EXIT_FAILURE;
    }

    // Create TCP socket
    socket_fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (socket_fd == -1) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Connect to server
    if (connect(socket_fd, result->ai_addr, result->ai_addrlen) == -1) {
        fprintf(stderr, "Failed to connect to server: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Construct HTTP request
    snprintf(request, BUFFER_SIZE, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);

    // Send HTTP request
    if (send(socket_fd, request, strlen(request), 0) == -1) {
        fprintf(stderr, "Failed to send HTTP request: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Receive HTTP response
    bytes_received = recv(socket_fd, response, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        fprintf(stderr, "Failed to receive HTTP response: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Print HTTP response
    response[bytes_received] = '\0';
    printf("%s\n", response);

    // Clean up
    free(hostname);
    free(path);
    freeaddrinfo(result);
    close(socket_fd);

    return EXIT_SUCCESS;
}