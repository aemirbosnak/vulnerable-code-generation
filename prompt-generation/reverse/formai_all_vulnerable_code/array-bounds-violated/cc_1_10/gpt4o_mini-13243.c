//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 80
#define BUFFER_SIZE 8192

void perform_http_get(const char *hostname, const char *path) {
    int sock;
    struct sockaddr_in server;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    int bytes_received;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return;
    }

    // Define server details
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(hostname);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) != 0) {
        perror("Connection to server failed");
        close(sock);
        return;
    }

    // Prepare the HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the HTTP GET request
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Failed to send request");
        close(sock);
        return;
    }

    // Receive the server's response
    while ((bytes_received = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response);
    }

    // Close the socket
    close(sock);
}

void print_usage() {
    printf("Usage: ./plugin <hostname> <path>\n");
    printf("Example: ./plugin example.com /\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    // Perform the HTTP GET request
    perform_http_get(hostname, path);

    return EXIT_SUCCESS;
}