//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    portno = 8080;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    puts("Waiting for connection...");

    if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    puts("Connection established with client");

    while(1) {
        memset(buffer, '\0', BUF_SIZE);

        sd = recv(newsockfd, buffer, BUF_SIZE, 0);
        if(sd <= 0) {
            if(sd == 0)
                printf("Client disconnected\n");
            else
                perror("recv failed");
            close(newsockfd);
            exit(EXIT_SUCCESS);
        }

        buffer[sd] = '\0';
        printf("Message received: %s\n", buffer);

        sd = send(newsockfd, buffer, strlen(buffer), 0);
        if(sd == -1) {
            perror("send failed");
            close(newsockfd);
            exit(EXIT_SUCCESS);
        }
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}