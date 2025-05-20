//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, portno = 110;
    char buffer[BUF_SIZE];
    struct addrinfo *servinfo;
    struct addrinfo hints;
    int rv;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("localhost", "pop3", &hints, &servinfo))!= 0) {
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

    printf("Connected to POP3 server\n");

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        printf("Enter command (quit to exit): ");
        fgets(buffer, BUF_SIZE, stdin);

        if (strcasecmp(buffer, "quit") == 0) {
            break;
        }

        send(sockfd, buffer, strlen(buffer), 0);
        recv(sockfd, buffer, BUF_SIZE - 1, 0);
        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}