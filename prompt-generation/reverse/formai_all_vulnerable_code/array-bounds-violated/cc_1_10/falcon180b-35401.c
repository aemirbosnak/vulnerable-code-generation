//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 12345
#define MAX 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, len, clientlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    int numbytes;
    char *message = "Welcome to the server!";

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

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        clientlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clientlen);

        if (newsockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s on port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        send(newsockfd, message, strlen(message), 0);
        bzero(buffer, MAX);

        while ((numbytes = recv(newsockfd, buffer, MAX, 0)) > 0) {
            buffer[numbytes] = '\0';
            printf("Received message: %s\n", buffer);
        }

        close(newsockfd);
    }

    return 0;
}