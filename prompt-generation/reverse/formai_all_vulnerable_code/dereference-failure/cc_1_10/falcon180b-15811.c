//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_LINE 1024
#define PORT 8080

int main() {
    int sockfd, newsockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];
    int rv;
    int numbytes;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if ((rv = getaddrinfo("localhost", "http", &hints, &servinfo))!= 0) {
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
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    freeaddrinfo(servinfo);

    while (1) {
        memset(s, 0, INET6_ADDRSTRLEN);
        inet_ntop(p->ai_family, getpeername(sockfd, NULL, NULL), s, INET6_ADDRSTRLEN);
        printf("connected to %s\n", s);

        char buffer[MAX_LINE];
        memset(buffer, 0, MAX_LINE);
        numbytes = read(sockfd, buffer, MAX_LINE);
        printf("received %d bytes\n", numbytes);
        printf("message: %s\n", buffer);

        char reply[MAX_LINE];
        memset(reply, 0, MAX_LINE);
        sprintf(reply, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\nContent-Length: %d\r\n\r\nHello, world!", strlen(buffer));
        send(sockfd, reply, strlen(reply), 0);

        close(sockfd);
        break;
    }

    return 0;
}