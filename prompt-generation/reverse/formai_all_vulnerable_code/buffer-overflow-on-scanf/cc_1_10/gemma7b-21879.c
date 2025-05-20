//Gemma-7B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>

#define PORT 8080

int main()
{
    int sockfd, newsockfd, clientlen, portnum;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    listen(sockfd, &clientlen);

    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, (int *) &clientlen);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    while (1)
    {
        memset(buffer, 0, 1024);
        recv(newsockfd, buffer, 1024, 0);

        printf("Received: %s", buffer);

        if (strcmp(buffer, "quit") == 0)
        {
            break;
        }

        memset(buffer, 0, 1024);
        printf("Enter message: ");
        scanf("%s", buffer);

        send(newsockfd, buffer, strlen(buffer) + 1, 0);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}