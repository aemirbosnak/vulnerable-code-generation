//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_REQUEST_SIZE 4096
#define MAX_RESPONSE_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char *host = argv[2];

    struct addrinfo hints, *server;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(host, NULL, &hints, &server)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        return 1;
    }

    int sock = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sock == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sock, server->ai_addr, server->ai_addrlen) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        return 1;
    }

    freeaddrinfo(server);

    char request[MAX_REQUEST_SIZE];
    char response[MAX_RESPONSE_SIZE];

    while (1) {
        memset(request, 0, MAX_REQUEST_SIZE);
        memset(response, 0, MAX_RESPONSE_SIZE);

        ssize_t bytes_received = recv(sock, request, MAX_REQUEST_SIZE, 0);
        if (bytes_received <= 0) {
            fprintf(stderr, "recv: %s\n", strerror(errno));
            return 1;
        }

        printf("Received request:\n%s", request);

        ssize_t bytes_sent = send(sock, response, strlen(response), 0);
        if (bytes_sent <= 0) {
            fprintf(stderr, "send: %s\n", strerror(errno));
            return 1;
        }

        printf("Sent response:\n%s", response);
    }

    return 0;
}