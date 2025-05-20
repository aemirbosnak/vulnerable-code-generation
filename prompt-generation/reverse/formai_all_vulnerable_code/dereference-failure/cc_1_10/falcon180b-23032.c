//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];
    int rv;
    const char *cause;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo("localhost", "12345", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            cause = strerror(errno);
            fprintf(stderr, "socket: %s\n", cause);
            continue;
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
            cause = strerror(errno);
            fprintf(stderr, "connect: %s\n", cause);
            close(sock);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        return 1;
    }

    while (1) {
        char buf[BUF_SIZE];
        int len;

        if ((len = recv(sock, buf, BUF_SIZE, 0)) == -1) {
            cause = strerror(errno);
            fprintf(stderr, "recv: %s\n", cause);
            close(sock);
            return 1;
        }

        buf[len] = '\0';
        printf("Received: %s\n", buf);
    }

    close(sock);
    return 0;
}