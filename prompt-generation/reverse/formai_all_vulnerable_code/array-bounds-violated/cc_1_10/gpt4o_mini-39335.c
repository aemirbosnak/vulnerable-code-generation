//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void http_get(const char *hostname, const char *path) {
    struct sockaddr_in server_address;
    struct hostent *host_entry;
    int sockfd;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int bytes_received;

    // Get the IP address of the hostname
    host_entry = gethostbyname(hostname);
    if (host_entry == NULL) {
        fprintf(stderr, "Failed to resolve hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("Socket creation failed");
    }

    // Setup the server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80); // HTTP port
    memcpy(&server_address.sin_addr.s_addr, host_entry->h_addr_list[0], host_entry->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        die("Connection to the server failed");
    }

    // Create HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the request to the server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        die("Failed to send request");
    }

    // Receive the response from the server
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the string
        printf("%s", response); // Print the response to stdout
    }

    if (bytes_received < 0) {
        die("Failed to receive response");
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