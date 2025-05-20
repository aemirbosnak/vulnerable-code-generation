//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 2048
#define PORT 80

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    return sockfd;
}

void connect_to_server(int sockfd, const char *hostname) {
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }
}

void send_http_request(int sockfd, const char *resource) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", resource, "localhost");

    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("Failed to send request");
    }
}

void receive_http_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0';  // Null-terminate the response
        printf("%s", response);
    }

    if (bytes_received < 0) {
        error("Failed to receive response");
    }
}

void cleanup(int sockfd) {
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <resource>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *resource = argv[2];

    int sockfd = create_socket();
    connect_to_server(sockfd, hostname);
    send_http_request(sockfd, resource);
    receive_http_response(sockfd);
    cleanup(sockfd);

    return 0;
}