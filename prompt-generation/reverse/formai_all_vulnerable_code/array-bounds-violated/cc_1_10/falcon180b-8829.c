//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define SERVER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[SERVER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        send(newsockfd, "Welcome to the Future!\n", strlen("Welcome to the Future!\n"), 0);
        while (1) {
            bzero(buffer, SERVER_SIZE);
            int bytes_received = recv(newsockfd, buffer, SERVER_SIZE, 0);
            if (bytes_received <= 0) {
                break;
            }
            buffer[bytes_received] = '\0';
            printf("Client: %s\n", buffer);
        }
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}