//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Sherlock Holmes
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

#define BUFFER_SIZE 1024
#define PORT "8080"

int main() {
    int sockfd, newsockfd, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(PORT));

    ret = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    ret = listen(sockfd, 5);
    if (ret == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd == -1) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        ret = recv(newsockfd, buffer, BUFFER_SIZE, 0);
        if (ret == -1) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        buffer[ret] = '\0';
        printf("Received message: %s\n", buffer);

        strcpy(buffer, "Received your message!");
        ret = send(newsockfd, buffer, strlen(buffer), 0);
        if (ret == -1) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}