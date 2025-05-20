//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_PORT "110"

int main(int argc, char *argv[])
{
    int sockfd, rv;
    struct addrinfo hints, *servinfo, *p;
    char recvbuf[512];
    char sendbuf[512];

    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <user>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(argv[1], POP3_PORT, &hints, &servinfo);
    if (rv != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(EXIT_FAILURE);
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect to the server\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(servinfo);

    rv = recv(sockfd, recvbuf, sizeof recvbuf, 0);
    if (rv == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    if (strncmp(recvbuf, "+OK", 3) != 0) {
        fprintf(stderr, "invalid server response: %s\n", recvbuf);
        exit(EXIT_FAILURE);
    }

    sprintf(sendbuf, "USER %s\r\n", argv[2]);
    rv = send(sockfd, sendbuf, strlen(sendbuf), 0);
    if (rv == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    rv = recv(sockfd, recvbuf, sizeof recvbuf, 0);
    if (rv == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    if (strncmp(recvbuf, "+OK", 3) != 0) {
        fprintf(stderr, "invalid server response: %s\n", recvbuf);
        exit(EXIT_FAILURE);
    }

    sprintf(sendbuf, "PASS %s\r\n", argv[3]);
    rv = send(sockfd, sendbuf, strlen(sendbuf), 0);
    if (rv == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    rv = recv(sockfd, recvbuf, sizeof recvbuf, 0);
    if (rv == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    if (strncmp(recvbuf, "+OK", 3) != 0) {
        fprintf(stderr, "invalid server response: %s\n", recvbuf);
        exit(EXIT_FAILURE);
    }

    sprintf(sendbuf, "LIST\r\n");
    rv = send(sockfd, sendbuf, strlen(sendbuf), 0);
    if (rv == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    while (1) {
        rv = recv(sockfd, recvbuf, sizeof recvbuf, 0);
        if (rv == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        if (strncmp(recvbuf, ".", 1) == 0) {
            break;
        }

        printf("%s", recvbuf);
    }

    sprintf(sendbuf, "QUIT\r\n");
    rv = send(sockfd, sendbuf, strlen(sendbuf), 0);
    if (rv == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    close(sockfd);

    return 0;
}