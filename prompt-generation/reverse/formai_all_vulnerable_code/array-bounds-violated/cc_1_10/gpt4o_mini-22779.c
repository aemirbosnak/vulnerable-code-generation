//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096
#define PORT 80

void error_handling(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_http_request(int sockfd, const char* hostname, const char* path) {
    char request[BUFFER_SIZE];

    // Create a GET request for the specified path
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n",
             path, hostname);

    // Send the request to the server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error_handling("Failed to send request");
    }
}

void receive_http_response(int sockfd) {
    char response[BUFFER_SIZE];
    int bytes_received;

    // Read the response from the server
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0';  // Null-terminate the response
        printf("%s", response);             // Print the response
    }

    if (bytes_received < 0) {
        error_handling("Failed to receive response");
    }
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handling("Failed to create socket");
    }
    return sockfd;
}

struct sockaddr_in create_server_address(const char* hostname) {
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(hostname);
    return server_address;
}

void connect_to_server(int sockfd, struct sockaddr_in server_address) {
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        error_handling("Failed to connect to server");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* hostname = argv[1];
    const char* path = argv[2];

    int sockfd = create_socket();
    struct sockaddr_in server_address = create_server_address(hostname);
    connect_to_server(sockfd, server_address);

    send_http_request(sockfd, hostname, path);
    receive_http_response(sockfd);

    close(sockfd);
    return EXIT_SUCCESS;
}