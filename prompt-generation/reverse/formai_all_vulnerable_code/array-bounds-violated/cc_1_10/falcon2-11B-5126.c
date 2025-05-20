//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 4096

int main() {
    // Create a TCP/IP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Create an IPv4 Internet address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Default port for HTTP
    server_addr.sin_addr.s_addr = inet_addr("www.example.com");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    // Send a GET request
    char request[BUF_SIZE] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    // Receive the response
    char response[BUF_SIZE];
    int bytes_read = recv(sockfd, response, BUF_SIZE, 0);
    if (bytes_read < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    response[bytes_read] = '\0';

    // Print the response
    printf("Response: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}