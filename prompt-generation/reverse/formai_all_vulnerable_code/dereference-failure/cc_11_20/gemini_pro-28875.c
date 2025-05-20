//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IMAP_PORT 143

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[1024];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(IMAP_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    n = read(sockfd, buf, sizeof(buf));
    if (n < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    snprintf(buf, sizeof(buf), "A001 LOGIN %s\r\n", argv[2]);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buf, sizeof(buf));
    if (n < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    snprintf(buf, sizeof(buf), "A002 LIST \"\" *\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buf, sizeof(buf));
    if (n < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    snprintf(buf, sizeof(buf), "A003 LOGOUT\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buf, sizeof(buf));
    if (n < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    close(sockfd);
    exit(0);
}