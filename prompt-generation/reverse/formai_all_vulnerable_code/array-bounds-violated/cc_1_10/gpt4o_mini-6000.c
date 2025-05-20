//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void print_usage(const char *prog_name) {
    printf("Usage: %s <hostname> <resource>\n", prog_name);
    printf("Example: %s www.example.com /\n", prog_name);
}

void http_get(const char *hostname, const char *resource) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int bytes_received;

    // Get host information
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Create a TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Prepare the HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", resource, hostname);
    
    // Send the request to the server
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Failed to send request");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Print the response
    printf("Response from server:\n");
    while ((bytes_received = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response); // Print the received chunk
    }

    if (bytes_received < 0) {
        perror("Failed to receive response");
    }

    close(sock); // Close the socket
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *resource = argv[2];

    http_get(hostname, resource);

    return EXIT_SUCCESS;
}