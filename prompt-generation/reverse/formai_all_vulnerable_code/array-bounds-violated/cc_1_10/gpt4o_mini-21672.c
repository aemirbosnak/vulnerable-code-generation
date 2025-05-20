//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 80
#define BUFFER_SIZE 4096

void perform_http_request(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Resolve hostname to IP address
    struct in_addr addr;
    if (inet_pton(AF_INET, hostname, &addr) <= 0) {
        perror("Invalid address or address not supported");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    memcpy(&server_addr.sin_addr, &addr, sizeof(addr));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection Failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Compose HTTP GET request
    snprintf(buffer, sizeof(buffer), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    
    // Send the request
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the response
    printf("Response from server:\n");
    int bytesReceived;
    while ((bytesReceived = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytesReceived] = '\0'; // Null-terminate the buffer
        printf("%s", buffer);
    }

    if (bytesReceived < 0) {
        perror("Receive failed");
    }

    // Clean up
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    perform_http_request(hostname, path);

    return 0;
}