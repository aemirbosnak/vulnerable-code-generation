//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096

void print_request(char *request) {
    printf("Request:\n%s\n", request);
}

void print_response(char *response) {
    printf("Response:\n%s\n", response);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

void connect_to_server(int sockfd, const char *server_ip, int server_port) {
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
}

void send_http_request(int sockfd, const char *request) {
    send(sockfd, request, strlen(request), 0);
}

void receive_http_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
    if (bytes_received < 0) {
        perror("Error receiving data");
    } else {
        response[bytes_received] = '\0';
        print_response(response);
    }
}

void build_http_request(char *request_buffer, const char *method, const char *path, const char *host) {
    snprintf(request_buffer, BUFFER_SIZE,
        "%s %s HTTP/1.1\r\n"
        "Host: %s\r\n"
        "Connection: close\r\n"
        "\r\n",
        method, path, host);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    const char *path = argv[3];

    char request[BUFFER_SIZE];
    build_http_request(request, "GET", path, server_ip);
    print_request(request);

    int sockfd = create_socket();
    connect_to_server(sockfd, server_ip, server_port);
    
    send_http_request(sockfd, request);
    receive_http_response(sockfd);

    close(sockfd);
    return 0;
}