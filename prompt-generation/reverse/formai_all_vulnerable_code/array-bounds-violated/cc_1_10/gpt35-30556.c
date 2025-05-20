//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    char sendline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <IPADDRESS> <PORT>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    fgets(sendline, MAXLINE, stdin);
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send error");
        exit(1);
    }

    memset(recvline, 0, sizeof(recvline));
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        perror("recv error");
        exit(1);
    }

    recvline[n] = '\0';
    printf("%s\n", recvline);

    close(sockfd);
    return 0;
}