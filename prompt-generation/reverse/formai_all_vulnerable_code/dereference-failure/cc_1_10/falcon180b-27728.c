//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

void die(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int gai_err = getaddrinfo(argv[1], NULL, &hints, &res);
    if (gai_err!= 0) {
        die("getaddrinfo");
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        die("socket");
    }

    int connect_err = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (connect_err!= 0) {
        die("connect");
    }

    char buf[1024];
    while (1) {
        int n = read(sockfd, buf, sizeof(buf));
        if (n <= 0) {
            break;
        }
        write(1, buf, n);
    }

    close(sockfd);
    return 0;
}