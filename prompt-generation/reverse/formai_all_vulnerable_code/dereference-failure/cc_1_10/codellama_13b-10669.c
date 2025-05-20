//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
/*
 * Building a HTTP Client example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <arpa/inet.h>

#define PORT 80
#define BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *path = argv[2];

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo *res;
    if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
        fprintf(stderr, "getaddrinfo() failed\n");
        return 1;
    }

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        fprintf(stderr, "socket() failed\n");
        return 1;
    }

    if (connect(sock, res->ai_addr, res->ai_addrlen) != 0) {
        fprintf(stderr, "connect() failed\n");
        return 1;
    }

    char req[BUF_SIZE];
    sprintf(req, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    if (send(sock, req, strlen(req), 0) == -1) {
        fprintf(stderr, "send() failed\n");
        return 1;
    }

    char buf[BUF_SIZE];
    int n;
    while ((n = recv(sock, buf, BUF_SIZE, 0)) > 0) {
        printf("%.*s", n, buf);
    }

    if (n == -1) {
        fprintf(stderr, "recv() failed\n");
        return 1;
    }

    close(sock);
    freeaddrinfo(res);

    return 0;
}