//Falcon-180B DATASET v1.0 Category: Chat server ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, addrlen, clilen, i, valread, sd;
    char buffer[MAX], message[MAX];
    struct sockaddr_in serv_addr, cli_addr;

    printf("Chat Server\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("socket failed");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    portno = atoi("1234");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("bind failed");
        exit(0);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    while (TRUE)
    {

        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        if (newsockfd < 0)
        {
            printf("connection failed");
            exit(0);
        }

        printf("Connection with client established\n");

        while (TRUE)
        {

            bzero(buffer, MAX);

            printf("Enter the message: ");
            scanf("%s", message);

            send(newsockfd, message, strlen(message), 0);

            valread = read(newsockfd, buffer, MAX);

            if (valread <= 0)
            {
                printf("Client disconnected\n");
                close(newsockfd);
                break;
            }

            printf("Message from client: %s\n", buffer);
        }

    }

    close(sockfd);

    return 0;

}