//Falcon-180B DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDR "127.0.0.1"

int main() {
    int sockfd;
    int n;
    char buffer[MAX_SIZE];
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if ((n = getaddrinfo(SERVER_ADDR, "8080", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(n));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sockfd);
        sockfd = -1;
    }

    if (sockfd == -1) {
        fprintf(stderr, "failed to connect\n");
        return 2;
    }

    while (1) {
        memset(buffer, 0, MAX_SIZE);
        fgets(buffer, MAX_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        n = recv(sockfd, buffer, MAX_SIZE, 0);
        if (n <= 0) {
            break;
        }
        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}