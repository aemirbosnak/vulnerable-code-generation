//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: inquisitive
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int sockfd, newsockfd, port, i, n;
    char buffer[1024];

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    newsockfd = accept(sockfd, NULL, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    i = 0;
    while (1)
    {
        n = read(newsockfd, buffer, 1024);
        if (n > 0)
        {
            printf("Client: %s\n", buffer);
            write(newsockfd, buffer, n);
        }
        else if (n == 0)
        {
            printf("Client disconnected\n");
            break;
        }
        else
        {
            perror("Error reading/writing");
            break;
        }
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}