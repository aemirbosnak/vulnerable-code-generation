//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], "http", &hints, &res) != 0) {
        fprintf(stderr, "Error: getaddrinfo()\n");
        exit(EXIT_FAILURE);
    }

    int sock_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock_fd == -1) {
        fprintf(stderr, "Error: socket()\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sock_fd, res->ai_addr, res->ai_addrlen) == -1) {
        fprintf(stderr, "Error: connect()\n");
        exit(EXIT_FAILURE);
    }

    char request_buf[MAX_BUF_SIZE];
    snprintf(request_buf, MAX_BUF_SIZE - 1,
             "GET / HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n",
             argv[1]);

    if (send(sock_fd, request_buf, strlen(request_buf), 0) == -1) {
        fprintf(stderr, "Error: send()\n");
        exit(EXIT_FAILURE);
    }

    char response_buf[MAX_BUF_SIZE];
    memset(response_buf, 0, sizeof(response_buf));

    ssize_t num_bytes = recv(sock_fd, response_buf, sizeof(response_buf) - 1, 0);
    if (num_bytes == -1) {
        fprintf(stderr, "Error: recv()\n");
        exit(EXIT_FAILURE);
    }
    response_buf[num_bytes] = '\0';

    printf("%s\n", response_buf);

    close(sock_fd);
    freeaddrinfo(res);

    return 0;
}