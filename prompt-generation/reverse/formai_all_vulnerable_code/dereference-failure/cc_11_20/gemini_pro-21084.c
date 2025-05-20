//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct addrinfo hints, *servinfo;
    char buffer[1024];
    int n;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[2]);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((getaddrinfo(argv[1], argv[2], &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error\n");
        return 1;
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd < 0) {
        fprintf(stderr, "socket error\n");
        return 1;
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) < 0) {
        fprintf(stderr, "connect error\n");
        return 1;
    }

    freeaddrinfo(servinfo);

    printf("Connected to the POP3 server.\n");

    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        fprintf(stderr, "read error\n");
        return 1;
    }

    printf("Server: %s\n", buffer);

    write(sockfd, "USER mail_exam@hmail.com\r\n", 27);

    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        fprintf(stderr, "read error\n");
        return 1;
    }

    printf("Server: %s\n", buffer);

    write(sockfd, "PASS mailbox_pass\r\n", 20);

    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        fprintf(stderr, "read error\n");
        return 1;
    }

    printf("Server: %s\n", buffer);

    write(sockfd, "STAT\r\n", 6);

    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        fprintf(stderr, "read error\n");
        return 1;
    }

    printf("Server: %s\n", buffer);

    write(sockfd, "LIST\r\n", 6);

    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        fprintf(stderr, "read error\n");
        return 1;
    }

    printf("Server: %s\n", buffer);

    write(sockfd, "TOP 1 5\r\n", 10);

    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        fprintf(stderr, "read error\n");
        return 1;
    }

    printf("Server: %s\n", buffer);

    write(sockfd, "RETR 1\r\n", 8);

    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        fprintf(stderr, "read error\n");
        return 1;
    }

    printf("Server: %s\n", buffer);

    write(sockfd, "QUIT\r\n", 6);

    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        fprintf(stderr, "read error\n");
        return 1;
    }

    printf("Server: %s\n", buffer);

    close(sockfd);

    return 0;
}