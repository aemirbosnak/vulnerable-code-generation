//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char host[1025];
    strncpy(host, argv[1], 1024);
    host[1024] = '\0';

    int port = atoi(argv[2]);

    struct addrinfo hints, *result, *rp;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int s = getaddrinfo(host, NULL, &hints, &result);
    if (s!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        return 1;
    }

    for (rp = result; rp!= NULL; rp = rp->ai_next) {
        int sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sock == -1) {
            perror("socket");
            continue;
        }

        if (connect(sock, rp->ai_addr, rp->ai_addrlen) == -1) {
            if (errno == ECONNREFUSED) {
                printf("%s:%d - closed\n", host, port);
            } else {
                perror("connect");
            }
            close(sock);
            continue;
        }

        printf("%s:%d - open\n", host, port);
        close(sock);
    }

    freeaddrinfo(result);
    return 0;
}