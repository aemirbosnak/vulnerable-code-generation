//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define REQUEST_SIZE 2048

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void http_get(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[REQUEST_SIZE];
    char response[BUFFER_SIZE];
    size_t bytes_read;

    // Creating a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("Error creating socket");
    }

    // Prepare the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);  // HTTP port
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        die("Connection failed");
    }
    
    // Format the HTTP GET request
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n", 
             path, hostname);
    
    // Send the GET request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        close(sockfd);
        die("Error sending request");
    }

    // Read response from the server
    printf("Response:\n");
    while ((bytes_read = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_read] = '\0';  // Null-terminate the received data
        printf("%s", response);
    }

    // Handle connection close and cleanup
    if (bytes_read < 0) {
        close(sockfd);
        die("Error receiving response");
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char **argv) {
    // Validate program arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    // Execute HTTP GET request
    http_get(hostname, path);

    return 0;  // Indicate successful completion
}