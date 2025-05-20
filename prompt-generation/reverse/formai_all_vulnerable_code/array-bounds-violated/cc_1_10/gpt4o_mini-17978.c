//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER 4096
#define SERVER "www.example.com"
#define PORT 80

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void http_client(const char *host, const char *page) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Get the server by hostname
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting");
    }

    // Prepare the HTTP request
    char request[MAX_BUFFER];
    snprintf(request, sizeof(request), "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", page, host);

    // Send the HTTP request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("Error sending request");
    }

    // Read the response
    char response[MAX_BUFFER];
    memset(response, 0, sizeof(response));
    int received_length;

    printf("Response from server:\n");
    while ((received_length = recv(sockfd, response, sizeof(response)-1, 0)) > 0) {
        response[received_length] = '\0'; // Null-terminate the string
        printf("%s", response);
        memset(response, 0, sizeof(response)); // Clear the buffer
    }

    if (received_length < 0) {
        error("Error reading response");
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    // Check for arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <page>\n", argv[0]);
        exit(1);
    }

    const char *host = SERVER;
    const char *page = argv[1];

    // Call the http_client function
    http_client(host, page);

    return 0;
}