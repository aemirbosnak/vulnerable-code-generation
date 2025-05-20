//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: introspective
// IMAP Client Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo *servinfo;
    if (getaddrinfo(host, NULL, &hints, &servinfo) != 0) {
        fprintf(stderr, "getaddrinfo error\n");
        return 1;
    }

    int sock = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sock < 0) {
        fprintf(stderr, "socket error\n");
        return 1;
    }

    if (connect(sock, servinfo->ai_addr, servinfo->ai_addrlen) < 0) {
        fprintf(stderr, "connect error\n");
        return 1;
    }

    freeaddrinfo(servinfo);

    char buf[BUF_SIZE];
    ssize_t bytes_read;

    while (1) {
        bytes_read = recv(sock, buf, BUF_SIZE, 0);
        if (bytes_read < 0) {
            fprintf(stderr, "recv error\n");
            break;
        }
        printf("Received %ld bytes from server\n", bytes_read);
        printf("Message: %s\n", buf);
    }

    close(sock);

    return 0;
}