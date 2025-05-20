//FormAI DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char const *argv[])
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, clientaddr;
    char buffer[BUFSIZE];
    char *hello = "Hello from server!";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation failed.\n");
        exit(0);
    }
    else
        printf("Socket successfully created.\n");

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("Socket binding failed.\n");
        exit(0);
    }
    else
        printf("Socket successfully bound.\n");

    if ((listen(sockfd, 5)) != 0)
    {
        printf("Listen failed.\n");
        exit(0);
    }
    else
        printf("Server listening.\n");

    socklen_t clientaddrLen = sizeof(clientaddr);

    connfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientaddrLen);
    if (connfd < 0)
    {
        printf("Connection failed.\n");
        exit(0);
    }
    else
        printf("Connection accepted.\n");

    while (1)
    {
        bzero(buffer, BUFSIZE);

        int bytesReceived = recv(connfd, buffer, BUFSIZE, 0);
        if (bytesReceived < 0)
        {
            printf("Error in reading.\n");
            exit(0);
        }
        else if (bytesReceived == 0)
        {
            printf("Connection closed.\n");
            break;
        }
        else
        {
            buffer[bytesReceived] = '\0';
            printf("Message from client: %s", buffer);

            send(connfd, hello, strlen(hello), 0);
        }
    }

    close(sockfd);
    return 0;
}