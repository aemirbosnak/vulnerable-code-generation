//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 993

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[256];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    snprintf(buffer, sizeof(buffer), "A001 LOGIN %s\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "A002 LIST \"\"\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "A003 LOGOUT\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buffer);

    close(sockfd);

    return 0;
}