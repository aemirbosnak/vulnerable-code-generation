//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: mind-bending
/*
 * A mind-bending HTTP client in C
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define MAX_HOSTNAME_LEN 128
#define MAX_PORT_LEN 6

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char hostname[MAX_HOSTNAME_LEN];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN);
    hostname[MAX_HOSTNAME_LEN - 1] = '\0';

    char port[MAX_PORT_LEN];
    strncpy(port, argv[2], MAX_PORT_LEN);
    port[MAX_PORT_LEN - 1] = '\0';

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo *server_addr;
    int err = getaddrinfo(hostname, port, &hints, &server_addr);
    if (err) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        exit(1);
    }

    int sock = socket(server_addr->ai_family, server_addr->ai_socktype, server_addr->ai_protocol);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sock, server_addr->ai_addr, server_addr->ai_addrlen) < 0) {
        perror("connect");
        exit(1);
    }

    char request[BUF_SIZE];
    snprintf(request, BUF_SIZE, "GET / HTTP/1.1\r\nHost: %s:%s\r\n\r\n", hostname, port);

    send(sock, request, strlen(request), 0);

    char response[BUF_SIZE];
    int n = recv(sock, response, BUF_SIZE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }

    printf("Response: %s\n", response);

    close(sock);
    freeaddrinfo(server_addr);

    return 0;
}