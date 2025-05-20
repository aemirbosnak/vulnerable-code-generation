//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CLIENTS 10

int main()
{
    int sockfd, newsockfd, client_fd[MAX_CLIENTS];
    struct sockaddr_in client_addr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    printf("Server is running on port 8080... \n");

    while (1)
    {
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
        if (newsockfd < 0)
        {
            perror("Error accepting client connection");
            continue;
        }

        client_fd[newsockfd] = newsockfd;

        printf("Client connected: %s\n", client_addr.sin_addr.s_addr);

        memset(buffer, 0, 1024);

        read(newsockfd, buffer, 1024);
        printf("Client: %s\n", buffer);

        write(newsockfd, buffer, 1024);
        printf("Server: %s\n", buffer);

        close(newsockfd);
        client_fd[newsockfd] = -1;
    }

    return 0;
}