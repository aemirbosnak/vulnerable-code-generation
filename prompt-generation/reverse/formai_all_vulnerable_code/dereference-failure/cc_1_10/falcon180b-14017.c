//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define MAX_HOST_LEN 256

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints;
    struct addrinfo *servinfo;
    char host[MAX_HOST_LEN];
    char buf[BUF_SIZE];
    int rv;
    int numbytes;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    strcpy(host, argv[1]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(host, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to %s\n", host);

    while (1) {
        memset(buf, 0, BUF_SIZE);
        numbytes = read(sockfd, buf, BUF_SIZE);

        if (numbytes == 0) {
            printf("Connection closed by server\n");
            break;
        } else if (numbytes < 0) {
            fprintf(stderr, "read: %s\n", strerror(errno));
            exit(1);
        }

        printf("Received %d bytes from server\n", numbytes);
        printf("Data: %s\n", buf);
    }

    close(sockfd);

    return 0;
}