//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 8192
#define PORT 80

// Function to create a socket and establish a connection
int create_socket_and_connect(const char *hostname) {
    struct hostent *host;
    struct sockaddr_in server_addr;
    int sockfd;

    if ((host = gethostbyname(hostname)) == NULL) {
        perror("Error getting host");
        exit(EXIT_FAILURE);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send HTTP GET request
void send_http_get_request(int sockfd, const char *path) {
    char request[BUFFER_SIZE];

    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\n"
                                         "Host: %s\r\n"
                                         "Connection: close\r\n\r\n", 
                                         path, "example.com");
    
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending request");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}

// Function to receive the HTTP response
void receive_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    printf("HTTP Response:\n");
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        perror("Error receiving response");
    }
}

// Main function to tie everything together
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *path = argv[1];
    const char *hostname = "example.com"; // Example hostname

    // Create socket and connect to the server
    int sockfd = create_socket_and_connect(hostname);

    // Send HTTP GET request
    send_http_get_request(sockfd, path);

    // Receive and print the HTTP response
    receive_http_response(sockfd);

    // Clean up and close the socket
    close(sockfd);
    return 0;
}