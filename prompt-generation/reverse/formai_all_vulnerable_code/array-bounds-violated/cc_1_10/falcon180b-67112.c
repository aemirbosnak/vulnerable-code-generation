//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd, newsockfd, portno, clilen, ret;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server, client;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(EXIT_FAILURE);
    }

    portno = 8080;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error binding socket\n");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    clilen = sizeof(client);
    newsockfd = accept(sockfd, (struct sockaddr *)&client, &clilen);
    if (newsockfd < 0) {
        printf("Error accepting connection\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        ret = recv(newsockfd, buffer, BUFFER_SIZE, 0);
        if (ret < 0) {
            printf("Error receiving data\n");
            exit(EXIT_FAILURE);
        }
        if (ret == 0) {
            printf("Connection closed\n");
            exit(EXIT_FAILURE);
        }
        buffer[ret] = '\0';
        printf("%s\n", buffer);
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}