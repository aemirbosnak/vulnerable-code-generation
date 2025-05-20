//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define HTTP_PORT 80

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse URL
    char *url = argv[1];
    char *hostname = url;
    char *path = strstr(url, "/");
    if(path == NULL) {
        path = "/";
    } else {
        *path = '\0';
        path++;
    }

    // Resolve hostname to IP address
    struct sockaddr_in server_address;
    if(inet_pton(AF_INET, hostname, &(server_address.sin_addr)) <= 0) {
        perror("Failed to resolve hostname");
        exit(EXIT_FAILURE);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(HTTP_PORT);

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if(connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // Prepare HTTP request
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

    // Send HTTP request
    if(send(socket_fd, request, strlen(request), 0) < 0) {
        perror("Failed to send HTTP request");
        exit(EXIT_FAILURE);
    }

    // Receive HTTP response
    char response[BUFFER_SIZE];
    int bytes_received = recv(socket_fd, response, BUFFER_SIZE, 0);
    if(bytes_received < 0) {
        perror("Failed to receive HTTP response");
        exit(EXIT_FAILURE);
    }
    response[bytes_received] = '\0';

    // Print HTTP response
    printf("%s", response);

    // Close socket
    close(socket_fd);

    return 0;
}