//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define BUFFER_SIZE 4096
#define USER_AGENT "CustomHTTPClient/1.0"

// Function to handle errors and display messages
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to create and connect a socket
int create_socket(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed");
    }

    // Initialize server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address/Address not supported");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    return sockfd;
}

// Function to send an HTTP GET request
void send_http_request(int sockfd, const char *hostname, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "User-Agent: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, hostname, USER_AGENT);

    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        handle_error("Failed to send request");
    }
}

// Function to receive the HTTP response
void receive_http_response(int sockfd) {
    char response[BUFFER_SIZE];
    ssize_t received_bytes;

    // Receive the response
    while ((received_bytes = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[received_bytes] = '\0'; // Null-terminate the response
        printf("%s", response); // Print the response
    }

    if (received_bytes < 0) {
        handle_error("Failed to receive response");
    }
}

// Main function to set up the HTTP client
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];
    int port = 80; // HTTP port

    // Create and connect the socket
    int sockfd = create_socket(hostname, port);
    printf("Connected to %s:%d\n", hostname, port);

    // Send the HTTP GET request
    send_http_request(sockfd, hostname, path);
    printf("HTTP request sent:\n%s\n", path);

    // Receive and display the HTTP response
    receive_http_response(sockfd);

    // Close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}