//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <unistd.h>
#include <ctype.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char recv_buf[BUF_SIZE];
    struct sockaddr_in serv_addr;

    if (argc!= 4) {
        printf("usage: %s <server_ip> <username> <password>\n", argv[0]);
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket failed\n");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("connect failed\n");
        return -1;
    }

    printf("connected to server\n");

    char auth_buf[100];
    sprintf(auth_buf, "USER %s\r\n", argv[2]);
    send(sockfd, auth_buf, strlen(auth_buf), 0);

    char pass_buf[100];
    sprintf(pass_buf, "PASS %s\r\n", argv[3]);
    send(sockfd, pass_buf, strlen(pass_buf), 0);

    while ((n = recv(sockfd, recv_buf, BUF_SIZE, 0)) > 0) {
        recv_buf[n] = '\0';
        printf("%s", recv_buf);
    }

    close(sockfd);
    return 0;
}