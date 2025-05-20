//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[BUFFERSIZE];

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listenfd, BACKLOG) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (TRUE)
    {
        printf("Waiting for connection...\n");
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr))) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection established with %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        while (TRUE)
        {
            bzero(buffer, BUFFERSIZE);
            if (recv(connfd, buffer, BUFFERSIZE, 0) <= 0)
            {
                if (errno!= EWOULDBLOCK)
                {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }
                else
                {
                    printf("No data received\n");
                }
            }
            else
            {
                printf("Received data: %s\n", buffer);
            }

            if (send(connfd, buffer, strlen(buffer), 0) < 0)
            {
                perror("send");
                exit(EXIT_FAILURE);
            }
        }

        close(connfd);
    }

    close(listenfd);

    return 0;
}