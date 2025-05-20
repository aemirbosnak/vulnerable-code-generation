//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char *message;
    int yes = 1;
    int valread;
    int sd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&yes, sizeof(int));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    while (TRUE) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        message = "Welcome to the server\r\n";
        ret = send(newsockfd, message, strlen(message), 0);
        if (ret < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        sd = dup(newsockfd);
        if (sd < 0) {
            perror("dup");
            exit(EXIT_FAILURE);
        }

        while ((valread = recv(sd, buffer, BUFFER_SIZE, 0)) > 0) {
            buffer[valread] = '\0';
            printf("%s", buffer);
        }
        close(sd);
    }

    return 0;
}