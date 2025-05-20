//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PROXY_PORT 8080

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, NULL, &hints, &result)!= 0) {
        error("getaddrinfo");
    }

    int sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock == -1) {
        error("socket");
    }

    if (connect(sock, result->ai_addr, result->ai_addrlen) == -1) {
        error("connect");
    }

    freeaddrinfo(result);

    char buffer[BUFFER_SIZE];
    while (1) {
        ssize_t bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        char request[BUFFER_SIZE];
        snprintf(request, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: Keep-Alive\r\n\r\n", host);

        send(sock, request, strlen(request), 0);

        while (1) {
            ssize_t bytes_sent = send(STDOUT_FILENO, buffer, bytes_received, 0);
            if (bytes_sent <= 0) {
                break;
            }

            ssize_t bytes_received_again = recv(sock, buffer, BUFFER_SIZE, 0);
            if (bytes_received_again <= 0) {
                break;
            }
        }
    }

    close(sock);
    return 0;
}