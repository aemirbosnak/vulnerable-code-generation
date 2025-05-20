//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define PORT 25
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    FILE *fp;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <server_address> <file_path>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Open %s failed\n", argv[2]);
        exit(1);
    }

    while (fgets(send_buf, BUF_SIZE, fp)!= NULL) {
        send_buf[strcspn(send_buf, "\r")] = '\0';
        n = send(sockfd, send_buf, strlen(send_buf), 0);
        if (n == -1) {
            perror("send failed");
            exit(1);
        }
    }

    fclose(fp);

    while (1) {
        bzero(recv_buf, BUF_SIZE);
        n = recv(sockfd, recv_buf, BUF_SIZE, 0);
        if (n == -1) {
            perror("recv failed");
            exit(1);
        }
        if (n == 0) {
            break;
        }
        recv_buf[n] = '\0';
        printf("%s", recv_buf);
    }

    close(sockfd);
    exit(0);
}