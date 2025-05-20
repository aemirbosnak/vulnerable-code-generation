//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 512

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints, *res, *p;
    char buf[BUFSIZE];
    int sockfd, n;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], argv[2], &hints, &res) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    for (p = res; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
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
        fprintf(stderr, "Failed to connect\n");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%s\n", argv[1], argv[2]);

    freeaddrinfo(res);

    while (1) {
        printf("> ");

        if (fgets(buf, BUFSIZE, stdin) == NULL) {
            break;
        }

        if (strlen(buf) > 0 && buf[strlen(buf)-1] == '\n') {
            buf[strlen(buf)-1] = '\0';
        }

        if (send(sockfd, buf, strlen(buf), 0) == -1) {
            perror("send");
            continue;
        }

        n = recv(sockfd, buf, BUFSIZE-1, 0);
        if (n == -1) {
            perror("recv");
            break;
        } else if (n == 0) {
            printf("Server disconnected\n");
            break;
        } else {
            buf[n] = '\0';
            printf("%s\n", buf);
        }
    }

    close(sockfd);

    return 0;
}