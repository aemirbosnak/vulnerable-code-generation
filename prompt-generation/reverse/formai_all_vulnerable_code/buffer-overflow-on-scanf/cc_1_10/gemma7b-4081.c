//Gemma-7B DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

#define SERVER_PORT 8080

int main()
{
    int sockfd, newsockfd, port, clientlen;
    char buffer[1024], filename[256], server_ip[16];
    struct sockaddr_in server_addr, client_addr;

    printf("Enter server IP address: ");
    scanf("%s", server_ip);

    printf("Enter port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

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

    printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

    while (1)
    {
        memset(buffer, 0, 1024);
        recv(newsockfd, buffer, 1024, 0);

        if (strcmp(buffer, "quit") == 0)
        {
            break;
        }

        printf("Client: %s\n", buffer);

        memset(buffer, 0, 1024);
        printf("Enter your message: ");
        scanf("%s", buffer);

        send(newsockfd, buffer, strlen(buffer) + 1, 0);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}