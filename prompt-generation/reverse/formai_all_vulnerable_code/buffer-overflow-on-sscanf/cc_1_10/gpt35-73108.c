//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 8192

int proxy(int clientfd) {
    char buf[BUFSIZE], method[BUFSIZE], url[BUFSIZE];
    struct sockaddr_in servaddr;
    int servfd;

    bzero(buf, BUFSIZE);
    recv(clientfd, buf, BUFSIZE, 0);

    sscanf(buf, "%s%s", method, url);
    if (strncasecmp("GET", method, strlen("GET"))) {
        close(clientfd);
        return -1;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    inet_aton(url + 7, &servaddr.sin_addr);

    servfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(servfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    send(servfd, buf, strlen(buf), 0);

    bzero(buf, BUFSIZE);
    int n;
    do {
        n = recv(servfd, buf, BUFSIZE, 0);
        if (n > 0) send(clientfd, buf, n, 0);
    } while (n > 0);
    close(servfd);
    close(clientfd);
    return 0;
}

int main(int argc, char **argv) {
    int servfd, clientfd;
    struct sockaddr_in servaddr, clientaddr;
    socklen_t clientlen = sizeof(clientaddr);

    servfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);
    bind(servfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(servfd, 128);

    while (1) {
        clientfd = accept(servfd, (struct sockaddr *)&clientaddr, &clientlen);
        pid_t pid = fork();
        if (pid == 0) {
            close(servfd);
            proxy(clientfd);
            exit(0);
        } else {
            close(clientfd);
        }
    }
    return 0;
}