//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main() {
    char *server = "pop.example.com";
    int port = 110;
    int sockfd;
    struct addrinfo hints, *serverinfo, *p;
    char buffer[BUFFER_SIZE];
    int n;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((n = getaddrinfo(server, NULL, &hints, &serverinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(n));
        exit(1);
    }

    for (p = serverinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    printf("connected to %s\n", server);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE);
        if (n <= 0) {
            if (n == 0) {
                printf("server closed connection\n");
            } else {
                perror("read");
            }

            break;
        }

        printf("received: %s", buffer);
    }

    close(sockfd);
    return 0;
}