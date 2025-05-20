//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX 1024
#define PORT "12345"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, clilen, len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        error("Socket failed");

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(PORT));

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("Bind failed");

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        puts("Waiting for connection...");
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
            error("Accept failed");

        puts("Connection established");

        while (1) {
            bzero(buffer, MAX);
            len = recv(newsockfd, buffer, MAX, 0);
            if (len <= 0) {
                puts("Disconnected");
                break;
            }

            buffer[len] = '\0';
            printf("Received message: %s\n", buffer);

            send(newsockfd, buffer, strlen(buffer), 0);
        }

        close(newsockfd);
    }

    return 0;
}