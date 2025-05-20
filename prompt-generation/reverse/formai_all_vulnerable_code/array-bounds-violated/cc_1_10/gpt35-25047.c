//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Define HTTP request
const char *HTTP_REQUEST = "GET / HTTP/1.1\r\n"
                            "Host: www.example.com\r\n"
                            "Connection: close\r\n"
                            "\r\n";

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        return -1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Failed to create socket");
        return -1;
    }

    // Set server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to connect to server");
        return -1;
    }

    // Send HTTP request to server
    if (send(sockfd, HTTP_REQUEST, strlen(HTTP_REQUEST), 0) == -1) {
        perror("Failed to send HTTP request");
        return -1;
    }

    // Receive response from server
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
    if (bytes_received < 0) {
        perror("Failed to receive response");
        return -1;
    }

    // Close socket
    if (close(sockfd) == -1) {
        perror("Failed to close socket");
        return -1;
    }

    return 0;
}