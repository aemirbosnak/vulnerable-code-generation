//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000
#define MAX 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Bind failed\n");
        exit(0);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    if (newsockfd < 0) {
        printf("Accept failed\n");
        exit(0);
    }

    while (1) {
        bzero(buffer, MAX);
        int n = recv(newsockfd, buffer, MAX, 0);
        if (n <= 0) {
            printf("Disconnected\n");
            break;
        }
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}