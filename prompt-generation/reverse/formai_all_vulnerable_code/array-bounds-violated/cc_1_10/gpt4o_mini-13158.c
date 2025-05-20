//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

// Function to create a socket and connect to the server
int create_socket(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    int sockfd;

    // Get the host information
    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        perror("gethostbyname failed");
        exit(EXIT_FAILURE);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send an HTTP GET request
void send_http_get(int sockfd, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n", path);
    send(sockfd, request, strlen(request), 0);
}

// Function to receive and display the HTTP response
void receive_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the received data
        printf("%s", response);
    }

    if (bytes_received < 0) {
        perror("Receive failed");
    }
}

// Main program to run the HTTP client
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    // Create a socket and connect to the server
    int sockfd = create_socket(hostname, 80);

    // Send the HTTP GET request
    send_http_get(sockfd, path);

    // Receive and print the response
    receive_response(sockfd);

    // Close the socket
    close(sockfd);
    return 0;
}