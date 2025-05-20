//FormAI DATASET v1.0 Category: Simple Web Server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>

#define BUF_SIZE 1024
#define METHOD_LEN 255

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);

    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len = sizeof(cliaddr);
    char buf[BUF_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 10) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", port);

    while (1) {
        connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        memset(buf, 0, BUF_SIZE);
        if ((n = recv(connfd, buf, BUF_SIZE, 0)) < 0) {
            perror("recv");
            close(connfd);
            continue;
        }

        char method[METHOD_LEN];
        char url[BUF_SIZE];
        char protocol[BUF_SIZE];
        sscanf(buf, "%s %s %s", method, url, protocol);

        if (strcmp(method, "GET") != 0) {
            char response[] = "HTTP/1.1 501 Not Implemented\r\n\r\n";
            send(connfd, response, strlen(response), 0);
        } else {
            if (strstr(url, "..") != NULL) {
                char response[] = "HTTP/1.1 400 Bad Request\r\n\r\n";
                send(connfd, response, strlen(response), 0);
            } else {
                char filepath[BUF_SIZE];
                snprintf(filepath, BUF_SIZE, ".%s", url);

                FILE *fp = fopen(filepath, "r");
                if (fp == NULL) {
                    char response[] = "HTTP/1.1 404 Not Found\r\n\r\n";
                    send(connfd, response, strlen(response), 0);
                } else {
                    char response[] = "HTTP/1.1 200 OK\r\n\r\n";
                    send(connfd, response, strlen(response), 0);

                    while ((n = fread(buf, 1, BUF_SIZE, fp)) > 0) {
                        send(connfd, buf, n, 0);
                    }   
                    fclose(fp);
                }
            }
        }

        close(connfd);
    }

    close(sockfd);

    return 0;
}