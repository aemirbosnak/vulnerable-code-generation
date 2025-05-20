//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX];

    if(argc < 2) {
        printf("usage :./server <port>\n");
        exit(0);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    if(listenfd == -1)
        error("socket failed");

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(atoi(argv[1]));

    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        error("bind failed");

    if(listen(listenfd, 5) < 0)
        error("listen");

    while(1) {
        printf("waiting for connections...\n");
        cliaddr.sin_family = AF_INET;
        cliaddr.sin_addr.s_addr = INADDR_ANY;
        cliaddr.sin_port = 0;
        socklen_t len = sizeof(cliaddr);

        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len);

        if(connfd < 0)
            error("accept");

        printf("client connected\n");

        while(1) {
            bzero(buffer, MAX);
            int n = recv(connfd, buffer, MAX, 0);

            if(n <= 0) {
                printf("client disconnected\n");
                close(connfd);
                break;
            }

            buffer[n] = '\0';
            printf("client : %s\n", buffer);

            send(connfd, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}