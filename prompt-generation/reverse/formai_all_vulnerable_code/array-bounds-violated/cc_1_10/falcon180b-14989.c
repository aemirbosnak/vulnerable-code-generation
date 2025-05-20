//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

void error(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[NI_MAXSERV];

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("www.example.com", "http", &hints, &servinfo))!= 0) {
        error("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            error("socket");
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sockfd);
        sockfd = -1;
    }

    if (sockfd == -1) {
        error("connect");
    }

    snprintf(s, sizeof(s), "GET / HTTP/1.0\r\nHost: www.example.com\r\n\r\n");
    send(sockfd, s, strlen(s), 0);

    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    while ((rv = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[rv] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    freeaddrinfo(servinfo);

    return 0;
}