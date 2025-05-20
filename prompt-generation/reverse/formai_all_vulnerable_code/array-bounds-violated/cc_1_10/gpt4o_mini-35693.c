//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096

void print_usage(const char *prog_name) {
    printf("Usage: %s <hostname> <port> <path>\n", prog_name);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

struct sockaddr_in setup_server_address(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Convert hostname to IP address
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }
    return server_addr;
}

void send_http_request(int sockfd, const char *hostname, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, hostname);

    send(sockfd, request, strlen(request), 0);
}

void receive_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    
    printf("Response from server:\n");
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null terminate the buffer
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        perror("recv failed");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    const char *path = argv[3];

    int sockfd = create_socket();
    struct sockaddr_in server_addr = setup_server_address(hostname, port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    send_http_request(sockfd, hostname, path);
    receive_http_response(sockfd);

    close(sockfd);
    return EXIT_SUCCESS;
}