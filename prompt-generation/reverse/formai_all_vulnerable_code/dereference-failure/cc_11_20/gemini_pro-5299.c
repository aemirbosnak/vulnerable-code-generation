//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    int sockfd, ret;
    struct sockaddr_in servaddr;
    char buf[BUFSIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // IMAP login
    snprintf(buf, sizeof(buf), "A001 LOGIN username password\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("IMAP login: %s", buf);

    // IMAP select
    snprintf(buf, sizeof(buf), "A002 SELECT inbox\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("IMAP select: %s", buf);

    // IMAP fetch
    snprintf(buf, sizeof(buf), "A003 FETCH 1 BODY[TEXT]\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("IMAP fetch: %s", buf);

    // IMAP logout
    snprintf(buf, sizeof(buf), "A004 LOGOUT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("IMAP logout: %s", buf);

    close(sockfd);

    return EXIT_SUCCESS;
}