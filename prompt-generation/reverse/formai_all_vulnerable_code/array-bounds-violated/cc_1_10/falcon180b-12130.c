//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

void fatal(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        fatal("socket");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fatal("bind");
    }

    if (listen(listenfd, 5) < 0) {
        fatal("listen");
    }

    while (1) {
        memset(&cliaddr, 0, sizeof(cliaddr));
        socklen_t len = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len)) < 0) {
            fatal("accept");
        }

        char ip[16];
        inet_ntop(AF_INET, &cliaddr.sin_addr, ip, sizeof(ip));
        printf("Connection from %s on port %d\n", ip, ntohs(cliaddr.sin_port));

        char buf[MAXLINE];
        while (recv(connfd, buf, MAXLINE, 0) > 0) {
            buf[recv(connfd, buf, MAXLINE, 0)] = '\0';
            printf("Received message: %s\n", buf);

            if (send(connfd, buf, strlen(buf), 0)!= strlen(buf)) {
                fatal("send");
            }
        }

        close(connfd);
    }

    return 0;
}