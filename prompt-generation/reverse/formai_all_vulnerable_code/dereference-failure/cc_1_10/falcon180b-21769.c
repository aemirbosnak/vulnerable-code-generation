//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];
    int rv;
    int numbytes;
    char buffer[BUFFER_SIZE];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("example.com", "ftp", &hints, &servinfo))!= 0) {
        error("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            error("socket");
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sockfd);
        sockfd = -1;
    }

    if (sockfd == -1) {
        error("connect");
    }

    printf("Connected to FTP server.\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        numbytes = send(sockfd, buffer, strlen(buffer), 0);
        if (numbytes == -1) {
            error("send");
        }

        memset(buffer, 0, BUFFER_SIZE);
        numbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (numbytes == -1) {
            error("recv");
        }

        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}