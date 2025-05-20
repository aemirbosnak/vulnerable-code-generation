//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct addrinfo hints, *res;
    char buf[BUF_SIZE];
    int len;
    const int on = 1;
    const char *host = argv[1];
    const char *port = argv[2];

    if(argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(host, port, &hints, &res);
    if(ret!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    if(connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    send(sockfd, "PING", strlen("PING"), 0);

    while(1) {
        len = recv(sockfd, buf, BUF_SIZE, 0);
        if(len <= 0) {
            break;
        }
        buf[len] = '\0';
        printf("%s", buf);
    }

    close(sockfd);
    return 0;
}