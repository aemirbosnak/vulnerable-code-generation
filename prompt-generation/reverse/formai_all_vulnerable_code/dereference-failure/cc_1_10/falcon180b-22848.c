//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define PORT 7
#define MAX 100
#define SA struct sockaddr

int main() {
    int sockfd, newsockfd, clilen, numbytes;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    int opt = TRUE;
    int addrlen = sizeof(cli_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (SA *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (TRUE) {
        puts("Waiting for connection...");
        numbytes = accept(sockfd, (SA *)&cli_addr, &addrlen);

        if (numbytes <= 0) {
            if (errno!= EINTR) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
        } else {
            printf("Connection from %s on port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
            send(newsockfd, "Connection Established\n", 21, 0);
        }
    }

    close(sockfd);
    return 0;
}