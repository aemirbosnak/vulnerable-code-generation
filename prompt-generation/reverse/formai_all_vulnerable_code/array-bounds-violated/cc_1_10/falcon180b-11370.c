//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char *host = "localhost";
    char *port = "21";
    int rv;
    int numbytes;
    char buf[BUF_SIZE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(host, port, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to FTP server.\n");

    while (1) {
        memset(buf, 0, BUF_SIZE);
        fgets(buf, BUF_SIZE, stdin);
        numbytes = strlen(buf);
        if (buf[numbytes - 1] == '\n') {
            buf[numbytes - 1] = '\0';
        }
        send(sockfd, buf, numbytes, 0);
    }

    close(sockfd);
    exit(0);
}