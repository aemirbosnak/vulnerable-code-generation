//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_RESPONSE_SIZE 4096
#define PORT 80

void make_http_request(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[512];
    char response[MAX_RESPONSE_SIZE];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Create HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    
    // Send the request
    send(sockfd, request, strlen(request), 0);
    printf("HTTP Request sent:\n%s\n", request);

    // Receive the response
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0';  // Null-terminate the response
        printf("HTTP Response received:\n%s", response);
    }

    // Check for errors
    if (bytes_received < 0) {
        perror("Receive error");
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\nExample: %s example.com /\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and path from command-line arguments
    const char *hostname = argv[1];
    const char *path = argv[2];

    // Make the HTTP request
    make_http_request(hostname, path);

    return EXIT_SUCCESS;
}