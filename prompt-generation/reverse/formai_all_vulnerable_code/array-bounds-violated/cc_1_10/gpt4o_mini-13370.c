//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define DEFAULT_PORT 80

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_http_request(int sockfd, const char *host, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, host);
    
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("Failed to send request");
    }
}

void read_http_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received;

    printf("Response:\n");
    
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response);
    }
    
    if (bytes_received < 0) {
        error("Failed to read response");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    const char *path = argv[2];
    
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Configure server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEFAULT_PORT);
    
    // Convert host to binary form
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        error("Invalid address / Address not supported");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    // Send HTTP GET request
    send_http_request(sockfd, host, path);

    // Read and print the HTTP response
    read_http_response(sockfd);
    
    // Close the socket
    close(sockfd);
    
    return 0;
}