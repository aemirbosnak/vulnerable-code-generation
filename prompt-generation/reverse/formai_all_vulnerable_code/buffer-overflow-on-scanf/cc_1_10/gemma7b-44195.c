//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 4096

int main()
{
    int sockfd, clientfd, serverfd;
    struct sockaddr_in clientSock, serverSock;
    char buffer[MAX_BUFFER_SIZE];
    char host[256], port[6];

    printf("Enter host name: ");
    scanf("%s", host);

    printf("Enter port number: ");
    scanf("%s", port);

    serverfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    serverSock.sin_addr.s_addr = inet_addr(host);
    serverSock.sin_port = htons(atoi(port));

    bind(serverfd, (struct sockaddr *)&serverSock, sizeof(serverSock));

    while (1)
    {
        clientfd = accept(serverfd, NULL, NULL);

        if (clientfd > 0)
        {
            printf("Client connected: %d\n", clientfd);

            // Send and receive data
            while (1)
            {
                int bytesRead = read(clientfd, buffer, MAX_BUFFER_SIZE);

                if (bytesRead > 0)
                {
                    write(clientfd, buffer, bytesRead);
                }
                else
                {
                    break;
                }
            }

            close(clientfd);
            printf("Client disconnected: %d\n", clientfd);
        }
    }

    return 0;
}