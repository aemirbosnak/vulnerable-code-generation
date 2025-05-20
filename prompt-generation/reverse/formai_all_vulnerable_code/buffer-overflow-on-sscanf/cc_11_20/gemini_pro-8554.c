//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFF_SIZE 4096

int main() {
    int listenfd, connfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;
    char buff[BUFF_SIZE];

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    if (bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        cli_len = sizeof(cli_addr);
        connfd = accept(listenfd, (struct sockaddr *)&cli_addr, &cli_len);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        while (1) {
            memset(buff, 0, BUFF_SIZE);
            int recv_len = recv(connfd, buff, BUFF_SIZE, 0);
            if (recv_len == -1) {
                perror("recv");
                break;
            } else if (recv_len == 0) {
                break;
            }

            int sscanf_ret = sscanf(buff, "GET %s HTTP/1.1", buff);
            if (sscanf_ret == 1) {
                int send_len = send(connfd, "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!</h1></body></html>", strlen("HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello World!</h1></body></html>"), 0);
                if (send_len == -1) {
                    perror("send");
                }
            } else {
                int send_len = send(connfd, "HTTP/1.1 400 Bad Request\n\n", strlen("HTTP/1.1 400 Bad Request\n\n"), 0);
                if (send_len == -1) {
                    perror("send");
                }
            }
        }

        close(connfd);
    }

    close(listenfd);
    return 0;
}