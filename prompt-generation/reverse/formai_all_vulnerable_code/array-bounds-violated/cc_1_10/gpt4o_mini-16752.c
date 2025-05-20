//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

// Function declarations
void print_http_response(int sock);
void perform_http_get(const char *host, const char *path);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    const char *path = argv[2];

    perform_http_get(host, path);

    return EXIT_SUCCESS;
}

void perform_http_get(const char *host, const char *path) {
    struct sockaddr_in server_addr;
    struct hostent *he;
    int sock;
    
    // Resolve the server's address
    if ((he = gethostbyname(host)) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Prepare the HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // Send the request
    if (send(sock, request, strlen(request), 0) == -1) {
        perror("send");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Print the server response
    print_http_response(sock);

    // Close the socket
    close(sock);
}

void print_http_response(int sock) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    // Receive the response
    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';  // Null-terminate the buffer
        printf("%s", buffer);            // Print the response
    }

    if (bytes_received == -1) {
        perror("recv");
    }
}