//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT "8080"
#define BUFFER_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[1024];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("localhost", PORT, &hints, &servinfo))!= 0) {
        error_handling("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            error_handling("socket");
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        error_handling("connect");
    }

    char request[1024] = "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    while ((rv = recv(sockfd, s, BUFFER_SIZE, 0)) > 0) {
        s[rv] = '\0';
        printf("%s", s);
    }

    if (rv == -1) {
        error_handling("recv");
    }

    close(sockfd);

    return 0;
}