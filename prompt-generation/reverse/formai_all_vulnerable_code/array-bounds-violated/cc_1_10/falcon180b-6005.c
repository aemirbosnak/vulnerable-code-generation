//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 100

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    listen(sockfd, 5);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));

        if (newsockfd < 0) {
            printf("Error accepting socket\n");
            exit(1);
        }

        printf("Connection established with client: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, MAX);

            n = recv(newsockfd, buffer, MAX, 0);

            if (n <= 0) {
                printf("Client disconnected\n");
                break;
            }

            buffer[n] = '\0';

            printf("Received message: %s\n", buffer);

            send(newsockfd, buffer, strlen(buffer), 0);
        }

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}