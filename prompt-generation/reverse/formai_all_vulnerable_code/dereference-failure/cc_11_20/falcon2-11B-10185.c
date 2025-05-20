//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 21

int main() {
    struct addrinfo hints, *servinfo, *p;
    int sockfd, rv;
    char buffer[1024], sendbuf[1024], recvbuf[1024];
    struct sockaddr_in server;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("client: connect");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        return 2;
    }

    if (send(sockfd, "USER anonymous\r\n", strlen("USER anonymous\r\n"), 0) == -1) {
        perror("client: send USER");
        close(sockfd);
        return 3;
    }

    if (send(sockfd, "PASS \r\n", strlen("PASS \r\n"), 0) == -1) {
        perror("client: send PASS");
        close(sockfd);
        return 4;
    }

    if (send(sockfd, "SYST\r\n", strlen("SYST\r\n"), 0) == -1) {
        perror("client: send SYST");
        close(sockfd);
        return 5;
    }

    if (send(sockfd, "TYPE I\r\n", strlen("TYPE I\r\n"), 0) == -1) {
        perror("client: send TYPE I");
        close(sockfd);
        return 6;
    }

    if (send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0) == -1) {
        perror("client: send LIST");
        close(sockfd);
        return 7;
    }

    while (1) {
        if (recv(sockfd, recvbuf, sizeof(recvbuf), 0) == -1) {
            perror("client: receive");
            close(sockfd);
            return 8;
        }

        printf("%s", recvbuf);

        if (strstr(recvbuf, "NLST")!= NULL) {
            break;
        }
    }

    printf("\n");

    close(sockfd);

    return 0;
}