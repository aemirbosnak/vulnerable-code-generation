//Falcon-180B DATASET v1.0 Category: Networking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int len;
    int addrlen = sizeof(cli_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
        if (newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        send(newsockfd, "Welcome to the server!\n", strlen("Welcome to the server!\n"), 0);

        while ((len = recv(newsockfd, buffer, sizeof(buffer), 0)) > 0) {
            buffer[len] = '\0';
            printf("Received message: %s\n", buffer);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}