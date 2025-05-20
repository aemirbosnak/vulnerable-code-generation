//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sock;
    struct addrinfo hints, *servinfo, *p;
    char s[BUF_SIZE];
    int rv;
    const char* port = "80";

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("www.google.com", port, &hints, &servinfo))!= 0) {
        error("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            error("socket");
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sock);
        sock = -1;
    }

    if (sock == -1) {
        error("connect");
    }

    while (1) {
        memset(s, 0, BUF_SIZE);
        if (fgets(s, BUF_SIZE, stdin) == NULL) {
            break;
        }

        send(sock, s, strlen(s), 0);
        if (recv(sock, s, BUF_SIZE, 0) <= 0) {
            break;
        }

        printf("Received: %s", s);
    }

    close(sock);
    freeaddrinfo(servinfo);

    return 0;
}