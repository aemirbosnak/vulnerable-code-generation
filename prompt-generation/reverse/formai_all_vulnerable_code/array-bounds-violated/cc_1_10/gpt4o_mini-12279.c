//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_BUFFER 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void http_get(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[MAX_BUFFER], response[MAX_BUFFER];
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        error("Error connecting to server");
    }

    // Prepare HTTP GET request
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, hostname);
    
    // Send HTTP request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        close(sockfd);
        error("Error sending request");
    }

    // Receive server response
    printf("Response from server:\n");
    ssize_t received;
    while ((received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[received] = '\0'; // Null-terminate the response
        printf("%s", response);
    }
    
    if (received < 0) {
        close(sockfd);
        error("Error receiving response");
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    http_get(hostname, path);
    return 0;
}