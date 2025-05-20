//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 4096

void build_http_request(const char *host, const char *path, char *request) {
    sprintf(request, "GET %s HTTP/1.1\r\n"
                     "Host: %s\r\n"
                     "Connection: close\r\n\r\n",
                     path, host);
}

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void http_client(const char *host, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    ssize_t bytes_received;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Socket creation failed");
    }

    // Set server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Convert host string to network address
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address / Address not supported");
    }

    // Establish connection to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to the server failed");
    }
    
    // Build HTTP GET request
    build_http_request(host, path, request);
    
    // Send the request to the server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        handle_error("Failed to send request");
    }

    // Receive and print the response from the server
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0';  // Null terminate the response
        printf("%s", response);
    }

    if (bytes_received < 0) {
        handle_error("Failed to receive response");
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    const char *path = argv[2];

    http_client(host, path);

    return 0;
}