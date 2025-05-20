//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(12345);

    ret = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        printf("Bind failed: %s\n", strerror(errno));
        exit(1);
    }

    clilen = sizeof(cli_addr);
    listen(sockfd, 5);

    while (1) {
        printf("Waiting for connection...\n");
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            printf("Accept failed: %s\n", strerror(errno));
            exit(1);
        }

        printf("Connection established with %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, 1024);
            ret = read(newsockfd, buffer, 1024);
            if (ret <= 0) {
                printf("Read failed: %s\n", strerror(errno));
                exit(1);
            }

            printf("Received message: %s\n", buffer);

            bzero(buffer, 1024);
            strcpy(buffer, "ACK");
            ret = write(newsockfd, buffer, strlen(buffer));
            if (ret <= 0) {
                printf("Write failed: %s\n", strerror(errno));
                exit(1);
            }
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}