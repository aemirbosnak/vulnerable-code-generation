//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 4096
#define DEFAULT_PORT 80

void print_response(const char *response) {
    printf("Response from server:\n");
    printf("%s\n", response);
}

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Error creating socket");
    }
    return sockfd;
}

void connect_to_server(int sockfd, const char *hostname, int port) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }
}

void send_http_request(int sockfd, const char *hostname, const char *path) {
    char request[MAX_BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n",
             path, hostname);
    
    send(sockfd, request, strlen(request), 0);
}

void receive_http_response(int sockfd) {
    char response[MAX_BUFFER_SIZE];
    memset(response, 0, sizeof(response));
    
    ssize_t bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
    if (bytes_received < 0) {
        handle_error("Failed to receive response");
    }

    response[bytes_received] = '\0';
    print_response(response);
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    int sockfd = create_socket();
    connect_to_server(sockfd, hostname, DEFAULT_PORT);
    send_http_request(sockfd, hostname, path);
    receive_http_response(sockfd);
    
    close(sockfd);
    return EXIT_SUCCESS;
}