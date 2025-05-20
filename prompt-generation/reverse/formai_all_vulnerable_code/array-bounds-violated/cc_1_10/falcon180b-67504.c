//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    char sendbuf[BUF_SIZE], recvbuf[BUF_SIZE];
    char *ptr;

    if (argc!= 4) {
        fprintf(stderr, "Usage:./client <server_ip> <server_port> <file_to_send>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(errno);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
    serveraddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect failed");
        exit(errno);
    }

    FILE *fp = fopen(argv[3], "r");
    if (fp == NULL) {
        fprintf(stderr, "File not found!\n");
        exit(1);
    }

    while ((n = fread(sendbuf, 1, BUF_SIZE, fp)) > 0) {
        sendbuf[n] = '\0';
        if (send(sockfd, sendbuf, n, 0) == -1) {
            perror("send failed");
            exit(errno);
        }
    }

    fclose(fp);

    while ((n = recv(sockfd, recvbuf, BUF_SIZE, 0)) > 0) {
        recvbuf[n] = '\0';
        fprintf(stdout, "%s", recvbuf);
    }

    close(sockfd);

    return 0;
}