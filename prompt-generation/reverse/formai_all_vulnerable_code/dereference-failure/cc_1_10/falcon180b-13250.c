//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT "8080"
#define MAX 100

int main() {
    int sockfd, newsockfd, clilen, numbytes;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(PORT));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    clilen = sizeof(cli_addr);
    if (getsockname(sockfd, (struct sockaddr *)&cli_addr, &clilen) < 0) {
        perror("getsockname");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s on port %s\n", inet_ntoa(cli_addr.sin_addr), PORT);

    while (1) {
        bzero(buffer, MAX);
        numbytes = read(sockfd, buffer, MAX);
        if (numbytes < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}