//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define PORT 8080
#define MAX_SIZE 100

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clilen, opt = 1;
    socklen_t addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_SIZE];
    int n;

    if (argc < 2) {
        printf("Use: %s <server/client>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "server") == 0) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket failed");
            exit(1);
        }

        setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(PORT);

        if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("bind failed");
            exit(1);
        }

        listen(sockfd, 5);
        clilen = sizeof(cli_addr);
        while (1) {
            newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
            if (newsockfd < 0) {
                perror("accept failed");
                exit(1);
            }

            printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

            send(newsockfd, "Welcome to the Tower of Hanoi game!\n", strlen("Welcome to the Tower of Hanoi game!\n"), 0);
        }
    } else if (strcmp(argv[1], "client") == 0) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket failed");
            exit(1);
        }

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        serv_addr.sin_port = htons(PORT);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("connect failed");
            exit(1);
        }

        while (1) {
            n = recv(sockfd, buffer, MAX_SIZE, 0);
            if (n < 0) {
                perror("recv failed");
                exit(1);
            }

            printf("%s", buffer);

            if (strcmp(buffer, "Welcome to the Tower of Hanoi game!\n") == 0) {
                send(sockfd, "Client connected.\n", strlen("Client connected.\n"), 0);
                break;
            }
        }
    } else {
        printf("Invalid argument\n");
        exit(1);
    }

    return 0;
}