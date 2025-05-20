//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 4096

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void http_request(int sockfd, const char *hostname, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        handle_error("Send failed");
    }
}

void parse_http_response(int sockfd) {
    char response[BUFFER_SIZE];
    int received_length;

    while ((received_length = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[received_length] = '\0'; // Null-terminate the response
        printf("%s", response);
    }

    if (received_length < 0) {
        handle_error("Receive failed");
    }
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Socket creation failed");
    }
    return sockfd;
}

struct sockaddr_in setup_server_address(const char *hostname) {
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname); // Convert hostname to IP address (IPv4)

    return server_addr;
}

void connect_to_server(int sockfd, struct sockaddr_in *server_addr) {
    if (connect(sockfd, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        handle_error("Connection to server failed");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    int sockfd = create_socket();
    struct sockaddr_in server_addr = setup_server_address(hostname);

    connect_to_server(sockfd, &server_addr);
    http_request(sockfd, hostname, path);
    parse_http_response(sockfd);

    close(sockfd);
    return 0;
}