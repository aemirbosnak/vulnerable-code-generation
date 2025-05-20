//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_LEN 1024
#define TIMEOUT_SEC 5
#define TIMEOUT_USEC 0

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *result, *rp;
    char hostname[MAX_HOSTNAME_LEN];
    int rv;
    int numbytes;
    char buffer[MAX_DATA_LEN];
    int timeout;
    fd_set writefds;
    struct timeval tv;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, NULL, &hints, &result))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sock, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    timeout = TIMEOUT_SEC * 1000000 + TIMEOUT_USEC;
    FD_ZERO(&writefds);
    FD_SET(sock, &writefds);

    strcpy(buffer, "PING");
    numbytes = send(sock, buffer, strlen(buffer), 0);
    if (numbytes == -1) {
        perror("send");
        exit(1);
    }

    tv.tv_sec = timeout / 1000000;
    tv.tv_usec = timeout % 1000000;

    if (select(sock + 1, NULL, &writefds, NULL, &tv) == -1) {
        perror("select");
        exit(1);
    }

    if (FD_ISSET(sock, &writefds)) {
        fprintf(stdout, "Host is alive\n");
    } else {
        fprintf(stdout, "Host is not responding\n");
    }

    close(sock);
    freeaddrinfo(result);

    exit(0);
}