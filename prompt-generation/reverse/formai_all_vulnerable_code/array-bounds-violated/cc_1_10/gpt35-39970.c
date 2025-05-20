//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER 1024

int main(int argc, char* argv[]) {

    // Check for valid input
    if(argc != 2) {
        printf("Usage: ./http_client_example <hostname>\n");
        exit(0);
    }

    struct addrinfo hints, *res;
    int sockfd;
    char buffer[MAX_BUFFER];
    memset(&hints, 0, sizeof(hints));

    // Fill in hints
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get address info
    int result = getaddrinfo(argv[1], "http", &hints, &res);
    if(result != 0) {
        printf("Error getting address info: %s\n", gai_strerror(result));
        exit(0);
    }

    // Create socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(sockfd < 0) {
        printf("Error creating socket.\n");
        exit(0);
    }

    // Connect to server
    if(connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        printf("Error connecting to server.\n");
        exit(0);
    }

    // Send HTTP request
    char request[MAX_BUFFER];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    if(send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error sending request.\n");
        exit(0);
    }

    // Receive response
    int bytes_received = 0;
    while((bytes_received = recv(sockfd, buffer, MAX_BUFFER, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    // Clean up
    close(sockfd);
    freeaddrinfo(res);

    return 0;
}