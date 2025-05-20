//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char recvline[MAX_LINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 3) {
        printf("usage: %s <IP address> <port number>", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen("file.txt", "w");
    if (fp == NULL) {
        printf("File error");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LINE + 1];
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "RETR file.txt\r\n");

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    while ((n = recv(sockfd, recvline, MAX_LINE, 0)) > 0) {
        recvline[n] = '\0';

        if (fputs(recvline, fp) == EOF) {
            printf("File error");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fp);
    close(sockfd);

    return 0;
}