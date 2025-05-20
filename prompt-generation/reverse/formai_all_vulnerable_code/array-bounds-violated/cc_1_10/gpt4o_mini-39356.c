//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    
    const char *hostname = argv[1];
    const char *port = argv[2];
    struct addrinfo hints, *res;
    int sockfd;
    char request[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    ssize_t n;

    // Set up the hints structure for getaddrinfo
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    // Get address info
    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        error("getaddrinfo");
    }

    // Create socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        error("socket");
    }

    // Connect to the server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        close(sockfd);
        error("connect");
    }

    // Free the addrinfo structure
    freeaddrinfo(res);

    // Create HTTP GET request
    snprintf(request, sizeof(request),
             "GET / HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", hostname);

    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("send");
    }

    // Receive and print the response
    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0'; // Null terminate the buffer
        printf("%s", buffer);
    }

    if (n < 0) {
        error("recv");
    }

    // Clean up
    close(sockfd);
    return 0;
}