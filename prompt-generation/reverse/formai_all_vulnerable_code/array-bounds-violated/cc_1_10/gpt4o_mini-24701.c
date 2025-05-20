//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void http_get(const char *hostname, const char *path) {
    struct sockaddr_in server_addr;
    int sock;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        die("Socket creation failed");
    }

    // Set up the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34"); // Example IP for example.com

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection to server failed");
    }

    // Prepare HTTP GET request
    snprintf(request, sizeof(request),
        "GET %s HTTP/1.1\r\n"
        "Host: %s\r\n"
        "Connection: close\r\n"
        "\r\n", path, hostname);

    // Send the request
    if (send(sock, request, strlen(request), 0) < 0) {
        die("Failed to send the request");
    }

    // Handle the response
    while (1) {
        ssize_t bytes_received = recv(sock, response, sizeof(response) - 1, 0);
        if (bytes_received < 0) {
            die("Failed to receive the response");
        }
        if (bytes_received == 0) {
            break; // EOF
        }

        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response); // Print the response to the console
    }

    // Clean up
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];
    
    printf("Sending HTTP GET request to %s%s...\n", hostname, path);
    http_get(hostname, path);
    printf("\nResponse received.\n");

    return 0;
}