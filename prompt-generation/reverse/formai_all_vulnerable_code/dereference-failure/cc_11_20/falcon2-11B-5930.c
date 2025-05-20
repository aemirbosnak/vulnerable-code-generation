//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <port> <message>\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints, *servinfo, *p;
    int rv;
    char buffer[BUFFER_SIZE];
    char *message = argv[3];
    char *host = argv[1];
    int port = atoi(argv[2]);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    rv = getaddrinfo(host, NULL, &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        if (send(sockfd, "EHLO localhost\r\n", 13, 0) == -1) {
            perror("send EHLO");
            close(sockfd);
            continue;
        }

        if (send(sockfd, "MAIL FROM:<me@example.com>\r\n", 28, 0) == -1) {
            perror("send MAIL FROM");
            close(sockfd);
            continue;
        }

        if (send(sockfd, "RCPT TO:<you@example.com>\r\n", 20, 0) == -1) {
            perror("send RCPT TO");
            close(sockfd);
            continue;
        }

        if (send(sockfd, "DATA\r\n", 6, 0) == -1) {
            perror("send DATA");
            close(sockfd);
            continue;
        }

        if (send(sockfd, "Subject: Test message\r\n", 23, 0) == -1) {
            perror("send Subject");
            close(sockfd);
            continue;
        }

        if (send(sockfd, "This is a test message\r\n.\r\n", 34, 0) == -1) {
            perror("send message");
            close(sockfd);
            continue;
        }

        if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
            perror("send QUIT");
            close(sockfd);
            continue;
        }

        close(sockfd);

        printf("Connection closed.\n");
        return 0;
    }

    fprintf(stderr, "Error: unable to resolve host.\n");
    exit(1);
}