//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char* argv[]) {
    struct addrinfo hints, *servinfo, *p;
    int status;
    int sockfd, n;
    char sendbuf[4096];
    char recvbuf[4096];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(NULL, "localhost", &hints, &servinfo);
    if (status!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("server: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("server: connect");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "server: failed to bind socket\n");
        freeaddrinfo(servinfo);
        return 1;
    }

    while (1) {
        bzero(sendbuf, sizeof sendbuf);
        bzero(recvbuf, sizeof recvbuf);

        n = write(sockfd, "HTTP/1.1 200 OK\r\n\r\n<html><head><title>Hello, World!</title></head><body><h1>Hello, World!</h1></body></html>\r\n", 72);
        if (n == -1) {
            perror("server: write");
            close(sockfd);
            break;
        }

        bzero(sendbuf, sizeof sendbuf);
        bzero(recvbuf, sizeof recvbuf);

        n = read(sockfd, recvbuf, sizeof recvbuf);
        if (n == -1) {
            perror("server: read");
            close(sockfd);
            break;
        }

        if (n == 0) {
            printf("server: connection closed\n");
            close(sockfd);
            break;
        }

        if (strcmp(recvbuf, "GET / HTTP/1.1\r\n\r\n") == 0) {
            printf("server: received GET request\n");
            send(sockfd, "HTTP/1.1 200 OK\r\n\r\n<html><head><title>Hello, World!</title></head><body><h1>Hello, World!</h1></body></html>\r\n", 72, 0);
        } else {
            send(sockfd, "HTTP/1.1 200 OK\r\n\r\n<html><head><title>Hello, World!</title></head><body><h1>Hello, World!</h1></body></html>\r\n", 72, 0);
        }
    }

    freeaddrinfo(servinfo);
    close(sockfd);
    return 0;
}