//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_LINE 1024
#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];
    int rv;
    char buffer[MAX_LINE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("smtp.example.com", "smtp", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
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
        fprintf(stderr, "Failed to connect\n");
        exit(1);
    }

    snprintf(buffer, sizeof(buffer), "EHLO %s\r\n", argv[0]);
    send(sockfd, buffer, strlen(buffer), 0);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        if ((rv = recv(sockfd, buffer, sizeof(buffer), 0)) <= 0) {
            break;
        }
        fprintf(stdout, "%s", buffer);
    }

    close(sockfd);
    freeaddrinfo(servinfo);
    return 0;
}