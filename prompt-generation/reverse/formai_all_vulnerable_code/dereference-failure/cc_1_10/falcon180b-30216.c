//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define POP3_PORT 110
#define USER "your_username"
#define PASS "your_password"

int main(int argc, char **argv) {
    int sockfd, ret;
    struct sockaddr_in servaddr;
    char send_buff[MAX_LINE], recv_buff[MAX_LINE];
    char *command = "USER ";
    char *response;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(errno);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret == -1) {
        perror("connect");
        exit(errno);
    }

    strcat(command, USER);
    strcat(command, "\r\n");
    send(sockfd, command, strlen(command), 0);

    response = recv_buff;
    ret = recv(sockfd, response, MAX_LINE, 0);
    if (ret == -1) {
        perror("recv");
        exit(errno);
    }

    printf("Server response: %s", response);

    strcat(command, PASS);
    strcat(command, "\r\n");
    send(sockfd, command, strlen(command), 0);

    response = recv_buff;
    ret = recv(sockfd, response, MAX_LINE, 0);
    if (ret == -1) {
        perror("recv");
        exit(errno);
    }

    printf("Server response: %s", response);

    close(sockfd);
    return 0;
}