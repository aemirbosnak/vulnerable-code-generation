//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1024

int main() {

    int sockfd, newsockfd, portno, clilen, ret;
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

    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    if (newsockfd < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        bzero(buffer, MAX);
        ret = recv(newsockfd, buffer, MAX, 0);

        if (ret < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        buffer[ret] = '\0';
        printf("Received message: %s\n", buffer);

        send(newsockfd, buffer, strlen(buffer), 0);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}