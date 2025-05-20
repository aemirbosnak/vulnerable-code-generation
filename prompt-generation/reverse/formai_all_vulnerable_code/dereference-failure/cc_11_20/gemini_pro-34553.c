//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 110
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char recvline[MAX_LINE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(DEFAULT_PORT);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    if (recv(sockfd, recvline, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", recvline);

    if (send(sockfd, "USER ", strlen("USER ") + strlen(argv[2]) + 2, 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(sockfd, recvline, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", recvline);

    if (send(sockfd, "PASS ", strlen("PASS ") + strlen(argv[2]) + 2, 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(sockfd, recvline, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", recvline);

    if (send(sockfd, "STAT ", strlen("STAT ") + 1, 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(sockfd, recvline, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", recvline);

    if (send(sockfd, "QUIT ", strlen("QUIT ") + 1, 0) < 0) {
        perror("send");
        exit(1);
    }

    close(sockfd);
    return 0;
}