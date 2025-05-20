//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    time_t t;
    struct tm *tm;
    char *timestamp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("Error creating socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 8080;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("Error binding to port");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        error_handling("Error accepting connection");
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        ret = recv(newsockfd, buffer, BUFFER_SIZE, 0);
        if (ret == 0) {
            break;
        }
        else if (ret < 0) {
            error_handling("Error receiving data");
        }

        time(&t);
        tm = localtime(&t);
        timestamp = asctime(tm);

        send(newsockfd, timestamp, strlen(timestamp), 0);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}