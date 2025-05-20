//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 100
#define PORT 8080
#define SA struct sockaddr

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, len, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero(&serv_addr, sizeof(serv_addr));

    portno = PORT;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (SA *)&serv_addr, sizeof(serv_addr))<0) {
        error("ERROR on binding");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while(1) {
        puts("Waiting for connection..");
        newsockfd = accept(sockfd, (SA *)&cli_addr, &clilen);

        if (newsockfd < 0) {
            error("ERROR on accept");
        }

        send(newsockfd, "WELCOME TO THE SERVER", strlen("WELCOME TO THE SERVER"), 0);

        while(1) {
            bzero(buffer, MAX);
            len = recv(newsockfd, buffer, MAX, 0);

            if(len <= 0) {
                error("Connection closed by peer");
            }

            fprintf(stdout, "Received string : %s\n", buffer);
            send(newsockfd, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}