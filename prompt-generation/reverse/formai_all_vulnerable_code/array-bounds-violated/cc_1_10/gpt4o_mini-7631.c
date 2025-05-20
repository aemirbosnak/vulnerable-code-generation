//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// A master key for unlocking URL treasures
#define MAX_URL 2048
#define PORT 80
#define BUFFER_SIZE 4096

// Function prototypes to lure you deeper into the puzzle
void parse_url(const char *url, char *host, char *path);
void http_request(const char *host, const char *path);
void process_server_response(int sockfd);

// The beginning of our HTTP journey
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <http://example.com/path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char host[MAX_URL], path[MAX_URL];
    parse_url(argv[1], host, path);

    printf("Fetching: %s\n", argv[1]);
    http_request(host, path);

    return EXIT_SUCCESS;
}

// Unravel the mysteries of the URL structure
void parse_url(const char *url, char *host, char *path) {
    const char *http_prefix = "http://";
    if (strncmp(url, http_prefix, strlen(http_prefix)) == 0) {
        url += strlen(http_prefix); // Move past 'http://'
    }

    char *slash_pos = strchr(url, '/');
    if (slash_pos) {
        strncpy(host, url, slash_pos - url);
        host[slash_pos - url] = '\0'; // Null-terminate the host
        strcpy(path, slash_pos); // Copy the path
    } else {
        strcpy(host, url);
        path[0] = '/'; // Default to root if no path is provided
        path[1] = '\0'; // Null-terminate the path
    }
}

// Awaken the forces of networking and send a request
void http_request(const char *host, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Opening a new realm of socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Summoning the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Transforming the host into an address of sorts
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Anchor down to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        exit(EXIT_FAILURE);
    }

    // Forge the request that's to be sent into the ether
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    send(sockfd, request, strlen(request), 0);

    // Unravel the response from the server
    process_server_response(sockfd);

    // Release the socket back into the wild
    close(sockfd);
}

// Process the server's response and display it to the seeker
void process_server_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received;

    // A lightweight loop to capture the incoming signals
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response); // Display the captured response
    }

    if (bytes_received < 0) {
        perror("Error receiving data");
    }
}