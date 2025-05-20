//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void print_response(char *response) {
    printf("Response:\n%s\n", response);
}

void get_http_response(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    int bytes_received;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP default port
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Prepare the HTTP GET request
    snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the HTTP request
    send(sockfd, request, strlen(request), 0);

    // Receive the server's response
    while ((bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null terminate the buffer
        print_response(response);
    }

    if (bytes_received < 0) {
        perror("Error receiving response");
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\nExample: %s www.example.com /\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    printf("Making GET request to http://%s%s...\n", hostname, path);
    get_http_response(hostname, path);

    return EXIT_SUCCESS;
}