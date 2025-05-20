//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/ioctl.h>

#define BACKLOG 5

int main(int argc, char *argv[])
{
    int listenfd, connfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    int opt = 1;
    fd_set readfds, writefds, exceptfds;
    struct timeval timeout;
    char buf[1024];
    struct sockaddr_in any_addr;
    int any_addr_len = sizeof(any_addr);
    int on = 1;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8080);

    if (bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (on) {
        FD_ZERO(&readfds);
        FD_ZERO(&writefds);
        FD_ZERO(&exceptfds);

        FD_SET(listenfd, &readfds);
        FD_SET(listenfd, &writefds);

        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        if (select(listenfd + 1, &readfds, &writefds, &exceptfds, &timeout) == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(listenfd, &readfds)) {
            clilen = sizeof(cli_addr);
            connfd = accept(listenfd, (struct sockaddr *)&cli_addr, &clilen);
            if (connfd == -1) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            FD_SET(connfd, &readfds);
            FD_SET(connfd, &writefds);

            if (write(connfd, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello World!</h1></body></html>\r\n", 95) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }

            close(connfd);
        }

        if (FD_ISSET(listenfd, &writefds)) {
            if (write(listenfd, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello World!</h1></body></html>\r\n", 95) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        if (FD_ISSET(listenfd, &exceptfds)) {
            if (ioctl(listenfd, FIONBIO, &on) == -1) {
                perror("ioctl");
                exit(EXIT_FAILURE);
            }
        }
    }

    close(listenfd);
    return 0;
}