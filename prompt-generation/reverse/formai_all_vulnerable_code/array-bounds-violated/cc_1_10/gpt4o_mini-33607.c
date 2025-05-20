//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 80
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void initialize_socket(int *sockfd, struct sockaddr_in *server_addr) {
    // Creating socket file descriptor
    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    memset(server_addr, 0, sizeof(*server_addr));
    server_addr->sin_family = AF_INET;
    server_addr->sin_port = htons(PORT);
}

void connect_to_server(int sockfd, struct sockaddr_in *server_addr, const char *hostname) {
    if (inet_pton(AF_INET, hostname, &server_addr->sin_addr) <= 0) {
        error("Invalid address / Address not supported");
    }
    
    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        error("Connection failed");
    }
}

void send_http_request(int sockfd, const char *hostname) {
    // Formulating the HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
    
    // Sending the HTTP request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("Failed to send request");
    }
}

void receive_http_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received;

    // Receiving the HTTP response
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the string
        printf("%s", response); // Print the response to the console
    }

    if (bytes_received < 0) {
        error("Failed to receive response");
    }
}

void cleanup(int sockfd) {
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    int sockfd;
    struct sockaddr_in server_addr;

    initialize_socket(&sockfd, &server_addr);
    connect_to_server(sockfd, &server_addr, hostname);
    send_http_request(sockfd, hostname);
    receive_http_response(sockfd);
    cleanup(sockfd);

    return 0;
}