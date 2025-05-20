//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_http_request(int sockfd, const char *host, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, host);
    
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("send");
    }
}

void receive_http_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null terminate the received data
        printf("%s", response);
    }

    if (bytes_received < 0) {
        error("recv");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        return 1;
    }
    
    const char *host = argv[1];
    const char *path = argv[2];
    
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("socket");
    }

    // Configure server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    
    // Convert hostname to IP address
    struct in_addr inAddress;
    if (inet_pton(AF_INET, host, &inAddress) <= 0) {
        error("inet_pton");
    }
    server_addr.sin_addr = inAddress;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("connect");
    }
    
    // Send HTTP GET request
    send_http_request(sockfd, host, path);
    
    // Receive and print HTTP response
    receive_http_response(sockfd);

    // Close the socket
    close(sockfd);
    return 0;
}