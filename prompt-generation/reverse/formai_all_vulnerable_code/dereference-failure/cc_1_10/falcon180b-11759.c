//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], NULL, &hints, &result)!= 0) {
        die("getaddrinfo");
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        die("socket");
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        die("connect");
    }

    char buf[BUF_SIZE];
    snprintf(buf, BUF_SIZE, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", argv[1]);

    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        die("send");
    }

    char response[BUF_SIZE];
    memset(response, 0, BUF_SIZE);

    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response, BUF_SIZE - 1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    close(sockfd);
    return 0;
}