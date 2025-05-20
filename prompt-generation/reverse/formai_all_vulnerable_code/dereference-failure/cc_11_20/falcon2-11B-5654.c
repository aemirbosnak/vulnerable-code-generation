//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <smtp_server> <message>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *message = argv[2];

    int sockfd = -1;
    struct addrinfo hints, *servinfo, *p;
    int rv;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(server, "25", &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        rv = connect(sockfd, p->ai_addr, p->ai_addrlen);
        if (rv == -1) {
            perror("connect");
            close(sockfd);
            sockfd = -1;
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to %s\n", server);
        return 1;
    }

    freeaddrinfo(servinfo);

    char buf[4096];
    char command[4096];

    sprintf(command, "EHLO localhost\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        close(sockfd);
        sockfd = -1;
        return 1;
    }

    sprintf(command, "MAIL FROM:<%s>\r\n", argv[1]);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        close(sockfd);
        sockfd = -1;
        return 1;
    }

    sprintf(command, "RCPT TO:<%s>\r\n", argv[2]);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        close(sockfd);
        sockfd = -1;
        return 1;
    }

    sprintf(command, "DATA\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        close(sockfd);
        sockfd = -1;
        return 1;
    }

    sprintf(command, "%s\r\n", message);
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        close(sockfd);
        sockfd = -1;
        return 1;
    }

    sprintf(command, "QUIT\r\n");
    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        close(sockfd);
        sockfd = -1;
        return 1;
    }

    close(sockfd);

    return 0;
}