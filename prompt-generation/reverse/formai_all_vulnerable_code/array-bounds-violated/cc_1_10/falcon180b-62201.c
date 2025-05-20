//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[4096];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        printf("Waiting for connection...\n");
        n = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &n);
        if (newsockfd < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            memset(buffer, 0, sizeof(buffer));
            n = recv(newsockfd, buffer, sizeof(buffer), 0);

            if (n <= 0) {
                printf("Connection closed by client\n");
                close(newsockfd);
                break;
            }

            buffer[n - 1] = '\0';

            printf("Received: %s\n", buffer);

            send(newsockfd, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}