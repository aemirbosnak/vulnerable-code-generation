//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024
#define PORT 110

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    char recv_buf[MAX_LINE];
    char send_buf[MAX_LINE];
    int n;
    int ret;

    if (argc!= 4) {
        printf("Usage:./program <server> <username> <password>\n");
        exit(1);
    }

    strcpy(send_buf, "USER ");
    strcat(send_buf, argv[2]);
    strcat(send_buf, "\r\n");

    strcpy(send_buf, "PASS ");
    strcat(send_buf, argv[3]);
    strcat(send_buf, "\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("socket failed\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("connect failed\n");
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    if (send(sockfd, send_buf, strlen(send_buf), 0) < 0) {
        printf("send failed\n");
        exit(1);
    }

    bzero(recv_buf, MAX_LINE);

    while (1) {
        n = recv(sockfd, recv_buf, MAX_LINE, 0);
        if (n <= 0) {
            printf("recv failed\n");
            exit(1);
        }
        recv_buf[n] = '\0';
        printf("%s", recv_buf);
        bzero(recv_buf, MAX_LINE);
    }

    close(sockfd);
    return 0;
}