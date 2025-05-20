//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: secure
/*
 * A unique C port scanner example program in a secure style
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PORTS 100

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints;
    struct addrinfo *result, *rp;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(argv[1], NULL, &hints, &result) != 0) {
        fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(errno));
        return 1;
    }

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        int sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sock == -1) {
            continue;
        }

        for (int port = 1; port <= MAX_PORTS; port++) {
            if (connect(sock, rp->ai_addr, rp->ai_addrlen) == 0) {
                printf("Port %d is open\n", port);
                close(sock);
                break;
            }
        }
    }

    freeaddrinfo(result);
    return 0;
}