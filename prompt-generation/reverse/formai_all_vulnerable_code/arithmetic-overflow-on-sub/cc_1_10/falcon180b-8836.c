//Falcon-180B DATASET v1.0 Category: Email Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define MAXLINE 1024

void die(const char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <host> <port> <username>\n", argv[0]);
        exit(1);
    }

    char* host = argv[1];
    char* port = argv[2];
    char* username = argv[3];

    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(host, port, &hints, &servinfo))!= 0) {
        die("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
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
        die("connect");
    }

    printf("Connected to %s:%s\n", host, port);

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin))!= -1) {
        if (line[read-1] == '\n') {
            line[--read] = '\0';
        }

        send(sockfd, line, read, 0);
    }

    free(line);

    close(sockfd);

    return 0;
}