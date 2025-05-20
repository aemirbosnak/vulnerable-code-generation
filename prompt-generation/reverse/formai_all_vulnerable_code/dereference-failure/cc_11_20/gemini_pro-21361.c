//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINE], recvline[MAX_LINE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    while (1) {
        printf("Enter command (QUIT to exit): ");
        if (fgets(sendline, MAX_LINE, stdin) == NULL) {
            perror("fgets error");
            exit(1);
        }

        if (strcmp(sendline, "QUIT\n") == 0) {
            break;
        }

        if (write(sockfd, sendline, strlen(sendline)) < 0) {
            perror("write error");
            exit(1);
        }

        while ((n = read(sockfd, recvline, MAX_LINE)) > 0) {
            recvline[n] = '\0';
            printf("%s", recvline);
        }

        if (n < 0) {
            perror("read error");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}