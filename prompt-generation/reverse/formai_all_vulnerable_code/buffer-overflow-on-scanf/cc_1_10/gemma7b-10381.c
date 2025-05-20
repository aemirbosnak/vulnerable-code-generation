//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define LISTEN_PORT 8888

int main()
{
    int sockfd, newsockfd, clientlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    char hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(LISTEN_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(LISTEN_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    clientlen = sizeof(client_addr);

    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    read(newsockfd, buffer, 1024);
    printf("Client: %s\n", buffer);

    write(newsockfd, buffer, 1024);
    close(newsockfd);

    return 0;
}