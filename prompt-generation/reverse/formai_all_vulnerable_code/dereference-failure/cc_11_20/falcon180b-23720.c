//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define true 1
#define false 0
#define PORT 5000
#define MAX 100

int main(int argc, char *argv[]) {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    servaddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listenfd, 5) == -1) {
        perror("listen failed");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while (true) {
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        if (connfd == -1) {
            if (errno == EINTR)
                continue;
            else {
                perror("accept failed");
                exit(1);
            }
        }

        printf("Connection from %s on port %d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (true) {
            bzero(buffer, MAX);
            n = recv(connfd, buffer, MAX, 0);
            if (n <= 0) {
                if (n == 0)
                    printf("Connection closed by client\n");
                else
                    perror("recv failed");
                close(connfd);
                break;
            }

            buffer[n] = '\0';
            printf("Received message: %s\n", buffer);

            if (send(connfd, buffer, n, 0)!= n) {
                perror("send failed");
                close(connfd);
                break;
            }
        }
    }

    return 0;
}