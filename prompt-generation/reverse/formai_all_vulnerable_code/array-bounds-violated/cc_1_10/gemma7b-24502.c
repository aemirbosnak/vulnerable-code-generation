//Gemma-7B DATASET v1.0 Category: Chat server ; Style: Dennis Ritchie
#include <stdio.h>
#include <netdb.h>

#define MAX_CLIENTS 10

int main()
{
    int sockfd, newsockfd, clientfd[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(65535);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        return 1;
    }

    for (;;)
    {
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
        if (newsockfd < 0)
        {
            perror("Error accepting client connection");
            continue;
        }

        clientfd[newsockfd] = newsockfd;

        printf("Client connected: %d\n", newsockfd);

        while (1)
        {
            int bytes_read = read(clientfd[newsockfd], buffer, 1024);
            if (bytes_read < 0)
            {
                perror("Error reading from client");
                break;
            }

            printf("Received: %s\n", buffer);

            int bytes_sent = write(clientfd[newsockfd], buffer, bytes_read);
            if (bytes_sent < 0)
            {
                perror("Error writing to client");
                break;
            }

            if (strcmp(buffer, "quit") == 0)
            {
                break;
            }
        }

        close(clientfd[newsockfd]);
        printf("Client disconnected: %d\n", newsockfd);
    }

    close(sockfd);

    return 0;
}