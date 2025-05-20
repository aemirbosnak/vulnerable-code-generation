//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void print_usage(const char *program_name) {
    printf("Usage: %s <host> <port> <path>\n", program_name);
    printf("Example: %s www.example.com 80 /\n", program_name);
}

int create_socket(const char *host, int port) {
    int sockfd;
    struct sockaddr_in server_address;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_address.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to the server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void send_http_request(int sockfd, const char *host, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, host);
    
    send(sockfd, request, strlen(request), 0);
}

void receive_http_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        perror("Failed to receive data");
    }
}

void clean_up(int sockfd) {
    close(sockfd);
    printf("Connection closed gracefully.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    int port = atoi(argv[2]);
    const char *path = argv[3];

    int sockfd = create_socket(host, port);
    send_http_request(sockfd, host, path);
    receive_http_response(sockfd);
    clean_up(sockfd);

    return EXIT_SUCCESS;
}