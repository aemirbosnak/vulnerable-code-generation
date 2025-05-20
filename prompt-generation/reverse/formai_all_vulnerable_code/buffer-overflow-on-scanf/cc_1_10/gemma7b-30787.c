//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PORT_RANGE 1-65535

int main()
{
    char hostname[256];
    printf("Enter hostname: ");
    scanf("%s", hostname);

    for (int port = PORT_RANGE; port <= PORT_RANGE; port++)
    {
        int sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
        if (sockfd == -1)
        {
            perror("Error creating socket");
            continue;
        }

        struct sockaddr_in servaddr;
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(port);
        servaddr.sin_addr.s_addr = inet_addr(hostname);

        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
        {
            perror("Error connecting to port");
            close(sockfd);
            continue;
        }

        char message[1024];
        printf("Enter message: ");
        scanf("%s", message);

        send(sockfd, message, strlen(message), 0);

        char received_message[1024];
        recv(sockfd, received_message, 1024, 0);

        printf("Received message: %s\n", received_message);

        close(sockfd);
    }

    return 0;
}