//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void fatal(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], argv[2], &hints, &result)!= 0) {
        fatal("getaddrinfo");
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        fatal("socket");
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        fatal("connect");
    }

    char buf[1024];
    while (1) {
        ssize_t n = read(sockfd, buf, sizeof(buf));
        if (n <= 0) {
            break;
        }
        buf[n] = '\0';
        printf("%s", buf);
    }

    close(sockfd);
    return 0;
}