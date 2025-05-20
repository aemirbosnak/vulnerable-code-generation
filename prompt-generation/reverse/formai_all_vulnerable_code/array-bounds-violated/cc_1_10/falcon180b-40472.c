//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int len;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) < 0) {
        perror("listen failed");
        exit(1);
    }

    while (TRUE) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(1);
        }

        while (TRUE) {
            bzero(buffer, sizeof(buffer));
            len = recv(newsockfd, buffer, sizeof(buffer), 0);
            if (len <= 0) {
                break;
            }
            buffer[len] = '\0';
            printf("Received message: %s\n", buffer);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}