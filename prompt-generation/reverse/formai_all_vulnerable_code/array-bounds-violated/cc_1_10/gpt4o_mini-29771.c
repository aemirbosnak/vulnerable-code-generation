//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096
#define HTTP_OK 200

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <hostname> <port> <path>\n", prog_name);
}

int create_socket(const char *hostname, int port) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host_info;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    host_info = gethostbyname(hostname);
    if (!host_info) {
        fprintf(stderr, "Failed to resolve hostname: %s\n", hostname);
        close(sock);
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host_info->h_addr, host_info->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

void send_http_request(int sock, const char *hostname, const char *path) {
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE,
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, hostname);

    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Failed to send request");
        close(sock);
        exit(EXIT_FAILURE);
    }
}

void receive_http_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        perror("Failed to receive response");
    }
}

void parse_http_response(char *response) {
    if (strstr(response, "HTTP/1.1 200 OK")) {
        printf("Response OK. Received:\n%s\n", response);
    } else {
        printf("Error in response:\n%s\n", response);
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

    int sock = create_socket(hostname, port);
    send_http_request(sock, hostname, path);

    char response[BUFFER_SIZE];
    int bytes_received = recv(sock, response, sizeof(response) - 1, 0);
    
    if (bytes_received > 0) {
        response[bytes_received] = '\0'; // Null-terminate the received data
        printf("HTTP Response received. Parsing...\n");
        parse_http_response(response);
    }

    close(sock);
    return EXIT_SUCCESS;
}