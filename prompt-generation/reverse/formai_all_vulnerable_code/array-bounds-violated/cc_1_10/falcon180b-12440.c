//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 100

int main() {
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        send(newsockfd, "Welcome to the server", strlen("Welcome to the server"), 0);

        while (recv(newsockfd, buffer, MAX, 0) > 0) {
            buffer[recv(newsockfd, buffer, MAX, 0)] = '\0';
            printf("Client: %s\n", buffer);
        }

        close(newsockfd);
    }

    return 0;
}