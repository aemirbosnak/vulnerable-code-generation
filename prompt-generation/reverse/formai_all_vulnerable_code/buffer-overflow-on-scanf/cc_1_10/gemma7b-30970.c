//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    int sockfd, newsockfd, port;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    printf("Client connected: %s:%d\n", client_addr.sin_addr.s_addr, client_addr.sin_port);

    while (1)
    {
        memset(buffer, 0, 1024);
        recv(newsockfd, buffer, 1024, 0);
        printf("Received: %s\n", buffer);

        memset(buffer, 0, 1024);
        printf("Enter your message: ");
        scanf("%s", buffer);
        send(newsockfd, buffer, strlen(buffer) + 1, 0);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}