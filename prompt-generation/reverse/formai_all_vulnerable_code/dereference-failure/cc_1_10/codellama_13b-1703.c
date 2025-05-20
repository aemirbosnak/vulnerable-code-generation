//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFLEN 1024

int main(int argc, char *argv[]) {
    struct addrinfo hints, *res, *p;
    int sockfd, ret;
    char sendbuf[BUFLEN], recvbuf[BUFLEN];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((ret = getaddrinfo(argv[1], argv[2], &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return 1;
    }

    for (p = res; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        return 1;
    }

    freeaddrinfo(res);

    fprintf(stdout, "Connected to %s\n", argv[1]);

    while (1) {
        fprintf(stdout, "Enter a message: ");
        fgets(sendbuf, BUFLEN, stdin);

        if (send(sockfd, sendbuf, strlen(sendbuf), 0) == -1) {
            perror("send");
            break;
        }

        if (recv(sockfd, recvbuf, BUFLEN, 0) == -1) {
            perror("recv");
            break;
        }

        fprintf(stdout, "Received: %s", recvbuf);
    }

    close(sockfd);

    return 0;
}