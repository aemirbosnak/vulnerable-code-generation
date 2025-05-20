//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define SERVER "example.com"
#define PORT 80
#define BUFFER_SIZE 4096

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_request(int sockfd, const char *host, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), 
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", 
             path, host);
    
    if (send(sockfd, request, strlen(request), 0) < 0) {
        handle_error("send failed");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the received data
        printf("%s", buffer); // Print the response to stdout
    }

    if (bytes_received < 0) {
        handle_error("recv failed");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *path = argv[1];
    char *host = SERVER;

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("socket failed");
    }

    // Set up the server address struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34"); // IP for example.com

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("connect failed");
    }

    // Send the HTTP GET request
    send_request(sockfd, host, path);

    // Receive and print the response
    receive_response(sockfd);

    // Close the socket
    close(sockfd);

    return 0;
}