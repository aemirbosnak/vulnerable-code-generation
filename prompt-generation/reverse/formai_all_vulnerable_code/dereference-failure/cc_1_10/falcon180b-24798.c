//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo *ai;
    struct sockaddr *addr;
    int ret;
    char buffer[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage: %s <host> <username> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(buffer, argv[1]);
    strcat(buffer, ":21");

    ret = getaddrinfo(buffer, NULL, NULL, &ai);
    if (ret!= 0) {
        printf("getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    sockfd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
    if (sockfd == -1) {
        printf("socket: %s\n", strerror(errno));
        exit(1);
    }

    ret = connect(sockfd, ai->ai_addr, ai->ai_addrlen);
    if (ret == -1) {
        printf("connect: %s\n", strerror(errno));
        exit(1);
    }

    strcpy(buffer, argv[1]);
    strcat(buffer, ":21");

    ret = send(sockfd, buffer, strlen(buffer), 0);
    if (ret == -1) {
        printf("send: %s\n", strerror(errno));
        exit(1);
    }

    addr = ai->ai_addr;
    if (addr->sa_family == AF_INET) {
        printf("Connected to %s\n", inet_ntoa(((struct sockaddr_in *) addr)->sin_addr));
    } else {
        printf("Connected to %s\n", inet_ntop(addr->sa_family, &(((struct sockaddr_in6 *) addr)->sin6_addr), buffer, BUFFER_SIZE));
    }

    ret = send(sockfd, argv[2], strlen(argv[2]), 0);
    if (ret == -1) {
        printf("send: %s\n", strerror(errno));
        exit(1);
    }

    ret = send(sockfd, argv[3], strlen(argv[3]), 0);
    if (ret == -1) {
        printf("send: %s\n", strerror(errno));
        exit(1);
    }

    close(sockfd);
    exit(0);
}