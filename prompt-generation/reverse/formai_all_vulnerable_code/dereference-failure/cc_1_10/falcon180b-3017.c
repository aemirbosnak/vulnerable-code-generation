//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX 100
#define PORT 8080
#define SA struct sockaddr

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    char buffer[MAX], *message = "HELLO";
    struct sockaddr_in serv_addr, cli_addr;
    char ip[20];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("socket failed");
        exit(1);
    }

    portno = PORT;

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (SA *)&serv_addr, sizeof(serv_addr))<0)
    {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (SA *)&cli_addr, &clilen);

    if (newsockfd < 0)
    {
        perror("accept");
        exit(1);
    }

    sd = accept(newsockfd, (SA *)NULL, NULL);

    if (sd < 0)
    {
        perror("accept");
        exit(1);
    }

    printf("Connection Established with Client\n");

    while(1)
    {
        bzero(buffer, MAX);

        if(recv(sd, buffer, MAX, 0) < 0)
        {
            perror("recv");
            exit(1);
        }

        for(i=0 ; buffer[i]!= '\0' ; i++)
        {
            message[i] = toupper(buffer[i]);
        }

        printf("Client : %s\n", message);

        if(strcmp(message, "BYE") == 0)
        {
            break;
        }

        send(sd, message, strlen(message), 0);
    }

    close(newsockfd);
    close(sd);

    return 0;
}