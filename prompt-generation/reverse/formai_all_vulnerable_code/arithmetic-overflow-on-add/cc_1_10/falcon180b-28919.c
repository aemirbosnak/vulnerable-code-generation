//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define TRUE  1
#define FALSE 0
#define PORT  8888
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clilen, i;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int numbytes;
    fd_set readfds;
    char *message = "Welcome to the server!";

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    while (TRUE) {
        clilen = sizeof(cli_addr);
        numbytes = select(sockfd + 1, &readfds, NULL, NULL, NULL);

        if ((numbytes == -1) || (FD_ISSET(sockfd, &readfds) == FALSE)) {
            continue;
        }

        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        send(newsockfd, message, strlen(message), 0);
        close(newsockfd);
    }

    return 0;
}