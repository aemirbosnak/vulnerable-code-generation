//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    // Parse URL into components
    char protocol[MAX_BUFF_SIZE], hostname[MAX_BUFF_SIZE], path[MAX_BUFF_SIZE];
    int port;
    if (sscanf(argv[1], "%[^:]://%[^:/]:%d/%[^\n]", protocol, hostname, &port, path) != 4) {
        fprintf(stderr, "Invalid URL: %s\n", argv[1]);
        exit(1);
    }

    // Set default values for the port and path components if not provided
    if (port == 0) {
        if (strcmp(protocol, "http") == 0) {
            port = 80;
        } else if (strcmp(protocol, "https") == 0) {
            port = 443;
        } else {
            fprintf(stderr, "Invalid URL: %s\n", argv[1]);
            exit(1);
        }
    }
    if (path[0] == '\0') {
        strcpy(path, "/");
    }

    // Resolve hostname to IP address
    struct sockaddr_in server_addr;
    struct hostent *server_host;
    server_host = gethostbyname(hostname);
    if (server_host == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
        exit(1);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy(server_host->h_addr, &server_addr.sin_addr.s_addr, server_host->h_length);
    server_addr.sin_port = htons(port);

    // Create socket and connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Generate HTTP request
    char request[MAX_BUFF_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s:%d\r\n"
             "Connection: close\r\n"
             "Accept: */*\r\n\r\n",
             path, hostname, port);

    // Send request to server
    write(sockfd, request, strlen(request));

    // Read response from server
    char response[MAX_BUFF_SIZE];
    int total_bytes_read = 0;
    int bytes_read;
    while ((bytes_read = read(sockfd, response+total_bytes_read, sizeof(response)-total_bytes_read)) > 0) {
        total_bytes_read += bytes_read;
    }

    // Parse response for status and content
    int status_code;
    char *content;
    if (sscanf(response, "HTTP/%*d.%*d %d ", &status_code) != 1) {
        fprintf(stderr, "Invalid HTTP response: %.*s\n", 50, response);
        exit(1);
    }
    content = strstr(response, "\r\n\r\n") + 4;

    // Print response
    printf("Status: %d\n", status_code);
    printf("Content:\n%.*s", total_bytes_read-(content-response), content);

    // Clean up
    close(sockfd);

    return 0;
}