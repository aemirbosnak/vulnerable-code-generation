//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXLINE];

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, MAXLINE);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (1) {
            memset(buffer, 0, MAXLINE);
            int n = read(connfd, buffer, MAXLINE);
            if (n == 0) {
                break;
            } else if (n == -1) {
                perror("read");
                close(connfd);
                break;
            }

            if (buffer[0] == 'G') {
                char *filename = &buffer[1];
                FILE *fp = fopen(filename, "r");
                if (fp == NULL) {
                    sprintf(buffer, "HTTP/1.0 404 Not Found\r\nContent-Length: 0\r\n\r\n");
                } else {
                    sprintf(buffer, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", (int)fread(buffer, 1, MAXLINE, fp));
                }
            } else {
                sprintf(buffer, "HTTP/1.0 400 Bad Request\r\nContent-Length: 0\r\n\r\n");
            }

            write(connfd, buffer, strlen(buffer));
            if (write(connfd, "\r\n", 2) == -1) {
                perror("write");
                close(connfd);
                break;
            }
        }

        close(connfd);
    }

    return 0;
}