//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char recvline[MAX_LINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buf[MAX_LINE];
    while (fgets(buf, MAX_LINE, stdin) != NULL) {
        if (send(sockfd, buf, strlen(buf), 0) < 0) {
            perror("send");
            close(sockfd);
            exit(1);
        }

        if ((n = recv(sockfd, recvline, MAX_LINE, 0)) < 0) {
            perror("recv");
            close(sockfd);
            exit(1);
        }
        recvline[n] = '\0';
        fputs(recvline, stdout);
    }

    close(sockfd);
    return 0;
}