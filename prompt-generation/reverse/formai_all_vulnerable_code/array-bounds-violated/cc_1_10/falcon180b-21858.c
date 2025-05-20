//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd, newsockfd, clilen, numbytes;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("socket failed\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("bind failed\n");
        exit(0);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
    if (newsockfd < 0) {
        printf("accept failed\n");
        exit(0);
    }

    printf("Connection accepted\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        numbytes = recv(newsockfd, buffer, BUFFER_SIZE, 0);
        if (numbytes <= 0) {
            printf("Connection closed\n");
            break;
        }
        buffer[numbytes] = '\0';
        printf("Received message: %s\n", buffer);

        send(newsockfd, buffer, strlen(buffer), 0);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}