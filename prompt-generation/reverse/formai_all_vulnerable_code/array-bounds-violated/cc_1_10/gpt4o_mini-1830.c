//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 80
#define BUFFER_SIZE 1024

// Function Declarations
void http_request(const char *hostname, const char *path);
void error_exit(const char *message);

// Main function to execute the HTTP client
int main(int argc, char *argv[]) {
    // Validate input
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    // Send HTTP request
    http_request(hostname, path);

    return EXIT_SUCCESS;
}

// Function to handle HTTP request communication
void http_request(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_exit("Socket creation failed");
    }

    // Set the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert hostname to IP address and set it
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error_exit("Invalid address or Address not supported");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("Connection to the server failed");
    }

    // Formulate the HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    
    // Send the request
    send(sockfd, request, strlen(request), 0);
    printf("HTTP request sent:\n%s\n", request);

    // Receive the response
    int bytes_received;
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response); // Print the response
    }

    // Close the socket
    close(sockfd);
}

// Function to handle errors and exit
void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}