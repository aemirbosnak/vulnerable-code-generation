//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    int n;
    int opt = 1;
    char *message = "Welcome to the post-apocalyptic world of TCP/IP programming!";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Waiting for a connection...\n");
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));

        if (newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection established with %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, BUF_SIZE);
            n = recv(newsockfd, buffer, BUF_SIZE, 0);

            if (n < 0) {
                perror("recv");
                exit(EXIT_FAILURE);
            }

            if (n == 0) {
                printf("Client disconnected\n");
                break;
            }

            buffer[n] = '\0';
            printf("Received message: %s\n", buffer);

            if (send(newsockfd, message, strlen(message), 0) < 0) {
                perror("send");
                exit(EXIT_FAILURE);
            }
        }

        close(newsockfd);
    }

    return 0;
}