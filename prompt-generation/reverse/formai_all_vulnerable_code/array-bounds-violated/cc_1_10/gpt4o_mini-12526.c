//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void print_usage() {
    printf("Usage: http_client <hostname> <port> <resource>\n");
    printf("Example: http_client example.com 80 /\n");
}

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void make_request(const char *hostname, const char *port, const char *resource) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Resolve hostname
    host = gethostbyname(hostname);
    if (host == NULL) {
        handle_error("Failed to resolve hostname");
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Failed to create socket");
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Failed to connect to the server");
    }

    // Create HTTP request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             resource, hostname);

    // Send HTTP request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        handle_error("Failed to send request");
    }

    // Read response
    char buffer[BUFFER_SIZE];
    while (1) {
        ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received < 0) {
            handle_error("Failed to receive response");
        } else if (bytes_received == 0) {
            break; // Connection closed
        }

        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("%s", buffer); // Print the response
    }

    // Clean up
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *port = argv[2];
    const char *resource = argv[3];

    make_request(hostname, port, resource);

    return EXIT_SUCCESS;
}