//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void parse_response(const char *response) {
    const char *header_end = strstr(response, "\r\n\r\n");
    if (header_end != NULL) {
        printf("HTTP Response Headers:\n");
        printf("%.*s\n", (int)(header_end - response), response);
        printf("HTTP Response Body:\n");
        printf("%s\n", header_end + 4);
    } else {
        printf("Invalid response format received.\n");
    }
}

void http_get(const char *hostname, const char *path) {
    int sock;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("Socket creation failed");
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        die("Invalid address / Address not supported");
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection failed");
    }

    // Build HTTP GET request
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, hostname);

    // Send the request
    send(sock, request, strlen(request), 0);

    // Receive the response
    int bytes_received = 0;
    bytes_received = recv(sock, response, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        die("Receive failed");
    }
    response[bytes_received] = '\0'; // Null-terminate the response

    // Print the response
    parse_response(response);

    // Clean up
    close(sock);
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