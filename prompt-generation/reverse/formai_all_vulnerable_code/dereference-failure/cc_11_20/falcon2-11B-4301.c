//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

#define PORT 21
#define MAXLINE 1024

int main() {
    int sockfd, connfd;
    struct sockaddr_in server;
    char line[MAXLINE];
    char filename[MAXLINE];
    FILE *fp;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect error");
        exit(1);
    }

    printf("Enter the name of the file to upload: ");
    fgets(filename, MAXLINE, stdin);

    if ((connfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(connfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect error");
        exit(1);
    }

    if (send(connfd, filename, strlen(filename), 0) < 0) {
        perror("send error");
        exit(1);
    }

    printf("Enter the file to upload: ");
    fgets(filename, MAXLINE, stdin);

    if (send(connfd, filename, strlen(filename), 0) < 0) {
        perror("send error");
        exit(1);
    }

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("open file error");
        exit(1);
    }

    while (!feof(fp)) {
        if (send(connfd, line, MAXLINE, 0) < 0) {
            perror("send error");
            exit(1);
        }

        if (recv(connfd, line, MAXLINE, 0) < 0) {
            perror("recv error");
            exit(1);
        }

        printf("%s\n", line);
    }

    fclose(fp);

    if (close(connfd) < 0) {
        perror("close error");
        exit(1);
    }

    if (close(sockfd) < 0) {
        perror("close error");
        exit(1);
    }

    return 0;
}