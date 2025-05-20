//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    int sockfd, newsockfd, port, n, i, j;
    char buffer[1024];
    struct sockaddr_in serv_addr;

    printf("Welcome to the C Port Scanner!\n");
    printf("Please specify the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    newsockfd = accept(sockfd, (struct sockaddr *)&serv_addr, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    printf("Connection established!\n");

    n = read(newsockfd, buffer, 1024);
    if (n < 0)
    {
        perror("Error reading data");
        exit(1);
    }

    printf("Received data: %s\n", buffer);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c ", buffer[i] & buffer[j]);
        }
        printf("\n");
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}