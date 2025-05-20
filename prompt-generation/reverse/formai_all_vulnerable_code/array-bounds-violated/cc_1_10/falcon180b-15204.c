//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUF_SIZE];
    int len;
    char *message;

    if (argc < 3) {
        printf("Usage:./server <portno> <message>\n");
        exit(0);
    }

    portno = atoi(argv[1]);
    message = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        send(newsockfd, message, strlen(message), 0);
        while ((len = recv(newsockfd, buffer, BUF_SIZE, 0)) > 0) {
            buffer[len] = '\0';
            printf("Received message: %s\n", buffer);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}