//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void parse_http_response(char *response) {
    char *header_end = strstr(response, "\r\n\r\n");
    if (header_end) {
        *header_end = '\0'; // Null-terminate headers
        printf("Response Headers:\n%s\n", response);
        printf("Response Body:\n%s\n", header_end + 4); // Skip past the headers
    } else {
        printf("Invalid HTTP response.\n");
    }
}

void http_get(const char *hostname, const char *path) {
    struct sockaddr_in server_addr;
    struct hostent *host_entry;
    int sockfd;
    char request[MAX_BUFFER], response[MAX_BUFFER];

    // Resolve the hostname
    host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        handle_error("Failed to resolve hostname");
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Socket creation failed");
    }

    // Configure server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    memcpy(&server_addr.sin_addr.s_addr, host_entry->h_addr, host_entry->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to the server failed");
    }

    // Formulate the HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        handle_error("Failed to send request");
    }

    // Receive the response
    int bytes_received;
    memset(response, 0, sizeof(response)); // Clear response buffer
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate response buffer
        parse_http_response(response);
    }

    if (bytes_received < 0) {
        handle_error("Failed to receive response");
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    http_get(hostname, path);
    return EXIT_SUCCESS;
}