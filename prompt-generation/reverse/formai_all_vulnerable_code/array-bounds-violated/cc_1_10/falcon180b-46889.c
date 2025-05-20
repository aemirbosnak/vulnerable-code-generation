//Falcon-180B DATASET v1.0 Category: Networking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <hostname> <port> <message>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *port = argv[2];
    char *message = argv[3];

    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, port, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sockfd);
        perror("connect");
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    send(sockfd, message, strlen(message), 0);

    char buffer[BUFFER_SIZE];
    while ((rv = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[rv] = '\0';
        printf("%s\n", buffer);
    }

    if (rv == -1) {
        perror("recv");
    }

    close(sockfd);
    return 0;
}