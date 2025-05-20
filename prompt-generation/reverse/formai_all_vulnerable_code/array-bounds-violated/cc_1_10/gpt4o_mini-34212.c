//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096

void print_http_response(const char *response) {
    printf("HTTP Response:\n");
    printf("%s\n", response);
}

void build_request(const char *host, const char *path, char *request_buffer) {
    snprintf(request_buffer, BUFFER_SIZE,
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, host);
}

int create_socket(const char *host, int port) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}

void http_request(const char *host, const char *path) {
    char request_buffer[BUFFER_SIZE];
    char response_buffer[BUFFER_SIZE];
    memset(response_buffer, 0, BUFFER_SIZE);

    build_request(host, path, request_buffer);

    int sock = create_socket(host, 80);

    send(sock, request_buffer, strlen(request_buffer), 0);
    printf("HTTPRequest sent:\n%s\n", request_buffer);

    int bytes_received = recv(sock, response_buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive response");
    } else {
        response_buffer[bytes_received] = '\0';  // Null-terminate the received buffer
        print_http_response(response_buffer);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    const char *path = argv[2];

    http_request(host, path);

    return 0;
}