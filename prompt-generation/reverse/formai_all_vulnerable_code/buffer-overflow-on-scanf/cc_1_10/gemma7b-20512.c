//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: funny
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int sockfd, newsockfd, port, numbytes, i, j;
    char buffer[1024], hostname[256];
    struct sockaddr_in sock_addr, client_addr;

    printf("Welcome to the Port Scanner, Mr. T!\n");
    printf("Please enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return -1;
    }

    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = inet_addr(hostname);

    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        return -1;
    }

    printf("Connection established with %s on port %d\n", hostname, port);

    numbytes = recv(newsockfd, buffer, 1024, 0);
    if (numbytes < 0)
    {
        perror("Error receiving data");
        return -1;
    }

    printf("Received data: %s\n", buffer);

    for (i = 0; i < numbytes; i++)
    {
        for (j = 0; j < numbytes; j++)
        {
            printf("%c ", buffer[j]);
        }
        printf("\n");
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}