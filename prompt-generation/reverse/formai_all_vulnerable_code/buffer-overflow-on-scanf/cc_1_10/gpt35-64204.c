//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 2) {
        printf("usage: ftpclient <IP address>\n");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket() error\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(21);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton() error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("connect() error\n");
        exit(1);
    }

    // login
    char username[MAXLINE], password[MAXLINE];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    char buf[MAXLINE];
    sprintf(buf, "USER %s\r\n", username);
    write(sockfd, buf, strlen(buf));
    read(sockfd, recvline, MAXLINE);
    sprintf(buf, "PASS %s\r\n", password);
    write(sockfd, buf, strlen(buf));
    read(sockfd, recvline, MAXLINE);

    // retrieve file list
    sprintf(buf, "PASV\r\n");
    write(sockfd, buf, strlen(buf));
    read(sockfd, recvline, MAXLINE);
    char *res = strstr(recvline, "(");
    int a, b, c, d, p1, p2;
    sscanf(res, "(%d,%d,%d,%d,%d,%d)", &a, &b, &c, &d, &p1, &p2);

    struct sockaddr_in dataaddr;
    memset(&dataaddr, 0, sizeof(dataaddr));
    dataaddr.sin_family = AF_INET;
    dataaddr.sin_port = htons(p1 * 256 + p2);
    inet_pton(AF_INET, argv[1], &dataaddr.sin_addr);

    int datasockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(datasockfd, (struct sockaddr *) &dataaddr, sizeof(dataaddr)) < 0) {
        printf("data connect() error\n");
        exit(1);
    }

    sprintf(buf, "LIST\r\n");
    write(sockfd, buf, strlen(buf));
    read(sockfd, recvline, MAXLINE);

    char listres[MAXLINE + 1];
    n = 0;
    while ((n = read(datasockfd, listres, sizeof(listres) - 1)) > 0) {
        listres[n] = 0;
        if (fputs(listres, stdout) == EOF) {
            printf("fputs error\n");
            exit(1);
        }
    }
    if (n < 0) {
        printf("read error\n");
        exit(1);
    }

    close(datasockfd);
    close(sockfd);
    exit(0);
}