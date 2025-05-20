//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAXLINE 1024
#define PORT "8888"

int main(int argc, char **argv) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[MAXLINE];
    int rv;
    int numbytes;

    /* Initialize hints */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    /* Get address information */
    if ((rv = getaddrinfo("localhost", PORT, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    /* Create socket */
    if ((sockfd = socket(servinfo->ai_family, servinfo->ai_socktype,
            servinfo->ai_protocol)) == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to server\n");

    /* Send data */
    while (fgets(s, MAXLINE, stdin)!= NULL) {
        if ((numbytes = send(sockfd, s, strlen(s), 0)) == -1) {
            fprintf(stderr, "send: %s\n", strerror(errno));
            exit(1);
        }
    }

    /* Receive data */
    while (1) {
        if ((numbytes = recv(sockfd, s, MAXLINE, 0)) == 0) break;
        if (numbytes == -1) {
            fprintf(stderr, "recv: %s\n", strerror(errno));
            exit(1);
        }
        s[numbytes] = '\0';
        printf("%s\n", s);
    }

    /* Close socket */
    close(sockfd);

    return 0;
}