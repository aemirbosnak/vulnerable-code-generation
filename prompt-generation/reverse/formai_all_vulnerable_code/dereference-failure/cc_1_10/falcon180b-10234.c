//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char *host, *user, *pass;
    int port = 110;
    int sockfd, ret;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];
    char *p;
    int len;

    if (argc!= 6) {
        printf("Usage: %s host user pass port\n", argv[0]);
        return -1;
    }

    host = argv[1];
    user = argv[2];
    pass = argv[3];
    port = atoi(argv[4]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%d\n", host, port);

    ret = send(sockfd, user, strlen(user), 0);
    if (ret == -1) {
        perror("send");
        exit(1);
    }

    ret = send(sockfd, pass, strlen(pass), 0);
    if (ret == -1) {
        perror("send");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        len = recv(sockfd, buffer, BUF_SIZE, 0);
        if (len <= 0) {
            printf("Disconnected\n");
            break;
        }

        p = strchr(buffer, '\r');
        if (p!= NULL) {
            *p = '\0';
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}