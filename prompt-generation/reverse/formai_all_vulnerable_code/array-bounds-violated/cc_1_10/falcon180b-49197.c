//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define IP "127.0.0.1"

int main()
{
    int sockfd, newsockfd, clientlen;
    struct sockaddr_in serveraddr, clientaddr;
    char buffer[BUFFER_SIZE];
    int count = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serveraddr.sin_family = AF_INET;
    inet_pton(AF_INET, IP, &serveraddr.sin_addr);
    serveraddr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    listen(sockfd, 5);

    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);
        clientlen = sizeof(clientaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientlen);

        if (newsockfd < 0)
        {
            printf("Error accepting connection\n");
            close(newsockfd);
            continue;
        }

        printf("Connection accepted from client %s\n", inet_ntoa(clientaddr.sin_addr));

        while (1)
        {
            memset(buffer, 0, BUFFER_SIZE);
            count = recv(newsockfd, buffer, BUFFER_SIZE, 0);

            if (count <= 0)
            {
                printf("Connection closed by client\n");
                close(newsockfd);
                break;
            }

            buffer[count] = '\0';
            printf("Received message from client: %s\n", buffer);

            send(newsockfd, buffer, strlen(buffer), 0);
        }
    }

    close(sockfd);
    return 0;
}