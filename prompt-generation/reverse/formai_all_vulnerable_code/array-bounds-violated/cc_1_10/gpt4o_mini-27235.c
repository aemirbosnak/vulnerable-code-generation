//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 8192

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void http_get(const char *host, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];

    // Creating a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("socket");
    }

    // Setting up the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        die("inet_pton");
    }

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("connect");
    }

    // Prepare the HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // Sending the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        die("send");
    }

    // Receiving the response
    printf("Response:\n");
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("%s", buffer);
    }

    // Close the socket
    close(sockfd);

    if (bytes_received < 0) {
        die("recv");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    const char *path = argv[2];

    // Make a HTTP GET request
    http_get(host, path);

    return EXIT_SUCCESS;
}