//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    int sockfd, newsockfd, port, i, host_port;
    char buffer[1024];
    struct sockaddr_in sock_addr, client_addr;

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    sock_addr.sin_port = htons(port);
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));

    printf("Listening for connections...\n");

    while (1)
    {
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
        if (newsockfd < 0)
        {
            perror("Error accepting connection");
            continue;
        }

        printf("Client connected: %s:%d\n", client_addr.sin_addr.s_addr, client_addr.sin_port);

        i = read(newsockfd, buffer, 1024);
        if (i < 0)
        {
            perror("Error reading data");
            continue;
        }

        printf("Received: %s\n", buffer);

        write(newsockfd, buffer, i);
        close(newsockfd);
    }

    return 0;
}