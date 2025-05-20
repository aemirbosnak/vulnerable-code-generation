//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, retval;
    struct addrinfo hints, *res;
    char buf[BUF_SIZE];
    int buf_len;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        return 1;
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    retval = getaddrinfo(argv[1], argv[2], &hints, &res);
    if (retval!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(retval));
        return 1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        return 1;
    }

    retval = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (retval == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    buf_len = send(sockfd, "PING", strlen("PING"), 0);
    if (buf_len == -1) {
        fprintf(stderr, "send: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    buf_len = recv(sockfd, buf, BUF_SIZE, 0);
    if (buf_len == -1) {
        fprintf(stderr, "recv: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    buf[buf_len] = '\0';
    printf("Received: %s\n", buf);

    close(sockfd);
    return 0;
}