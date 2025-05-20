//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Constant definitions for HTTP client
#define MAX_BUFFER_SIZE 4096
#define DEFAULT_PORT 80

// Function prototype declarations
void perform_http_get(const char *hostname, const char *path);
void print_error(const char *msg);

int main(int argc, char *argv[]) {
    // Ensure the user provides a URL
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <http://hostname/path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse the provided URL to extract hostname and path
    char *url = argv[1];
    char *host_start = strstr(url, "//");
    char *path_start = strchr(url, '/');

    if (host_start != NULL) {
        host_start += 2; // Move past "//"
    } else {
        host_start = url; // No schema, use the full URL
    }

    char *hostname = strndup(host_start, path_start != NULL ? path_start - host_start : strlen(host_start));
    char *path = path_start ? strdup(path_start) : strdup("/");

    // Perform the HTTP GET request
    perform_http_get(hostname, path);

    // Clean up allocated memory
    free(hostname);
    free(path);
    return 0;
}

void perform_http_get(const char *hostname, const char *path) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Create a socket for communication
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        print_error("Error opening socket");
    }

    // Resolve the hostname to an IP address
    server = gethostbyname(hostname);
    if (server == NULL) {
        print_error("No such host");
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(DEFAULT_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        print_error("Error connecting");
    }

    // Create the HTTP GET request string
    char request[MAX_BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the request
    ssize_t bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        print_error("Error sending request");
    }

    // Buffer for incoming data
    char response[MAX_BUFFER_SIZE];
    // Read and print the response
    ssize_t bytes_received;
    
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the buffer
        printf("%s", response); // Print the response
    }

    if (bytes_received < 0) {
        print_error("Error reading response");
    }

    // Close the socket
    close(sockfd);
}

void print_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}