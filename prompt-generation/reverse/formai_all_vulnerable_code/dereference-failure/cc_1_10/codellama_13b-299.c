//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: configurable
// Program to test network connectivity using ICMP echo requests and responses

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    struct addrinfo hints;
    struct addrinfo *res, *rp;
    int s;
    int ret;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;

    if ((ret = getaddrinfo(host, "echo", &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return 1;
    }

    for (rp = res; rp != NULL; rp = rp->ai_next) {
        if ((s = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(s, rp->ai_addr, rp->ai_addrlen) == -1) {
            close(s);
            perror("connect");
            continue;
        }

        break;
    }

    if (rp == NULL) {
        fprintf(stderr, "Could not connect\n");
        return 1;
    }

    freeaddrinfo(res);

    char buf[BUFSIZE];
    memset(buf, 0, BUFSIZE);
    if (send(s, buf, BUFSIZE, 0) == -1) {
        perror("send");
        close(s);
        return 1;
    }

    struct sockaddr_storage peer;
    socklen_t peer_len = sizeof(struct sockaddr_storage);
    if (recvfrom(s, buf, BUFSIZE, 0, (struct sockaddr *)&peer, &peer_len) == -1) {
        perror("recvfrom");
        close(s);
        return 1;
    }

    close(s);

    if (inet_ntop(AF_INET, &((struct sockaddr_in *)&peer)->sin_addr, buf, BUFSIZE) == NULL) {
        perror("inet_ntop");
        return 1;
    }

    printf("Received echo reply from %s\n", buf);

    return 0;
}