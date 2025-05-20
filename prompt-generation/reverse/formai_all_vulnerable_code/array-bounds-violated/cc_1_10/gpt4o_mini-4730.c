//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define PORT "80"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void build_http_request(const char *host, const char *path, char *request, size_t size) {
    snprintf(request, size,
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, host);
}

void send_http_request(const char *host, const char *path) {
    int sockfd;
    struct addrinfo hints, *res;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    ssize_t bytes_received;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, PORT, &hints, &res) != 0) {
        error("getaddrinfo");
    }

    // Creating socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        freeaddrinfo(res);
        error("socket");
    }

    // Connecting to the server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        close(sockfd);
        freeaddrinfo(res);
        error("connect");
    }

    freeaddrinfo(res); // All done with this

    // Build the HTTP request
    build_http_request(host, path, request, sizeof(request));

    // Send the HTTP request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        close(sockfd);
        error("send");
    }

    // Receive the response
    printf("Response:\n");
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response);
    }

    if (bytes_received < 0) {
        close(sockfd);
        error("recv");
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    const char *path = argv[2];

    send_http_request(host, path);

    return 0;
}