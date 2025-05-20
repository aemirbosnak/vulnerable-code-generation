//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define IMAP_PORT "993"
#define BUFSIZE 1024

void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char buf[BUFSIZE];
    struct addrinfo hints, *res;

    if (argc != 3) {
        fprintf(stderr, "usage: %s hostname username\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], IMAP_PORT, &hints, &res) != 0)
        error("getaddrinfo error");

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1)
        error("socket error");

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1)
        error("connect error");

    freeaddrinfo(res);

    if (recv(sockfd, buf, BUFSIZE, 0) == -1)
        error("recv error");

    char *login = "1 LOGIN ";
    int login_len = strlen(login);
    char *username = argv[2];
    int username_len = strlen(username);
    char *passtxt = "Password: ";
    int passtxt_len = strlen(passtxt);

    if (send(sockfd, login, login_len, 0) == -1)
        error("send error");

    if (send(sockfd, username, username_len, 0) == -1)
        error("send error");

    if (recv(sockfd, buf, BUFSIZE, 0) == -1)
        error("recv error");

    if (strncmp(buf + login_len, "+ ", 2) != 0)
        error("server error");

    printf("Enter your password: ");
    fflush(stdout);
    fgets(buf, BUFSIZE, stdin);
    int password_len = strlen(buf) - 1;
    buf[password_len] = '\r';
    buf[password_len + 1] = '\n';

    if (send(sockfd, buf, password_len + 2, 0) == -1)
        error("send error");

    if (recv(sockfd, buf, BUFSIZE, 0) == -1)
        error("recv error");

    if (strncmp(buf + login_len, "OK ", 3) != 0)
        error("authentication error");

    char *select = "1 SELECT inbox\r\n";
    int select_len = strlen(select);

    if (send(sockfd, select, select_len, 0) == -1)
        error("send error");

    if (recv(sockfd, buf, BUFSIZE, 0) == -1)
        error("recv error");

    if (strncmp(buf, "* ", 2) != 0)
        error("server error");

    printf("%s", buf);

    if (recv(sockfd, buf, BUFSIZE, 0) == -1)
        error("recv error");

    printf("%s", buf);

    char *logout = "1 LOGOUT\r\n";
    int logout_len = strlen(logout);

    if (send(sockfd, logout, logout_len, 0) == -1)
        error("send error");

    if (recv(sockfd, buf, BUFSIZE, 0) == -1)
        error("recv error");

    if (strncmp(buf, "* BYE ", 6) != 0)
        error("server error");

    printf("%s", buf);

    if (recv(sockfd, buf, BUFSIZE, 0) == -1)
        error("recv error");

    printf("%s", buf);

    close(sockfd);

    return 0;
}