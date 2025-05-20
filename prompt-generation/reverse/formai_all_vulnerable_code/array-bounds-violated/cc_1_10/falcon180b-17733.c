//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define BACKLOG 5

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in seraddr, cliaddr;
    int addrlen = sizeof(cliaddr);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&seraddr, 0, sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    seraddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&seraddr, sizeof(seraddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &addrlen);
        if (connfd == -1) {
            perror("accept");
            exit(1);
        }

        char buffer[1024];
        int nbytes = 0;

        while ((nbytes = recv(connfd, buffer, sizeof(buffer), 0)) > 0) {
            buffer[nbytes] = '\0';
            printf("Client message: %s\n", buffer);
        }

        close(connfd);
    }

    return 0;
}