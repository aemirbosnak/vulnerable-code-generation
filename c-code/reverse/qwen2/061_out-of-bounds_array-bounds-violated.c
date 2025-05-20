#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_address>\n", argv[0]);
        return 1;
    }

    int sockfd;
    struct sockaddr_in serv_addr;

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    // Fill in the address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/ Address not supported\n");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return 1;
    }

    // Send HTTP GET request
    const char *request = "GET / HTTP/1.1\r\nHost: ";
    send(sockfd, request, strlen(request), 0);
    send(sockfd, argv[1], strlen(argv[1]), 0);
    send(sockfd, "\r\nConnection: close\r\n\r\n", 23, 0);

    // Receive and print the response
    char buffer[BUFFER_SIZE];
    while (read(sockfd, buffer, BUFFER_SIZE - 1) > 0) {
        printf("%s", buffer);
    }

    // Close the socket
    close(sockfd);

    return 0;
}
