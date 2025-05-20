//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// Constants
#define SERVER_PORT 80
#define BUFFER_SIZE 4096

// Function prototype
void print_http_response(int sockfd);

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_address;
    char request[BUFFER_SIZE];

    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Prepare the server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);

    // Convert the hostname to IP address
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("Invalid address format");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Prepare the HTTP GET request
    snprintf(request, sizeof(request),
             "GET / HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", argv[1]);

    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Send failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Print the HTTP response
    print_http_response(sockfd);

    // Close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}

// Function to read and print the HTTP response
void print_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    printf("HTTP Response:\n");
    
    // Read response from server
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        perror("Receive failed");
    }
}