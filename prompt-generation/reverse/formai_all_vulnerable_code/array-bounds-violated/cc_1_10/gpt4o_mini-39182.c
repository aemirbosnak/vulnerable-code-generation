//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define BUFFER_SIZE 4096

void print_usage(const char *program_name) {
    printf("Usage: %s <URL>\n", program_name);
}

int http_get(const char *url) {
    char host[256];
    char path[256] = "/";
    int port = 80;

    // Parse the URL to extract the host and path
    if (sscanf(url, "http://%255[^/]/%255[^\n]", host, path) < 1) {
        if (sscanf(url, "http://%255s", host) < 1) {
            fprintf(stderr, "Invalid URL format. Please use http://<host>/<path>\n");
            return -1;
        }
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Setup server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    
    // Convert host address to binary form
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/ Address not supported for %s\n", host);
        close(sock);
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return -1;
    }

    // Prepare the HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // Send the request
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Send failed");
        close(sock);
        return -1;
    }

    // Receive and print the response
    char response[BUFFER_SIZE];
    int received;
    while ((received = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[received] = '\0'; // Null-terminate the string
        printf("%s", response);
    }

    if (received < 0) {
        perror("Receive failed");
    }

    // Close the socket
    close(sock);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    return http_get(argv[1]);
}