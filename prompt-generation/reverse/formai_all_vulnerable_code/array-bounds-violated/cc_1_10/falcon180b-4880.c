//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define TRUE   1
#define FALSE  0
#define PORT 12345
#define MAX 100

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, clilen, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) 
    {
        printf("socket failed");
        exit(0);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons( PORT );

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("bind failed");
        exit(0);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    if (newsockfd < 0)
    {
        printf("accept failed");
        exit(0);
    }

    printf("Connection Established\n");

    while(1)
    {
        bzero(buffer, MAX);
        sd = recv(newsockfd, buffer, MAX, 0);

        if(sd <= 0)
        {
            printf("Disconnected\n");
            break;
        }

        buffer[sd] = '\0';
        printf("Received Data : %s\n", buffer);

        send(newsockfd, buffer, strlen(buffer), 0);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}