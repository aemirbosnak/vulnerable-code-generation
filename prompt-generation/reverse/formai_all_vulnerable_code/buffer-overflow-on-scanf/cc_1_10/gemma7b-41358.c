//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
    char hostname[256];
    int port = 53;
    int attempts = 0;
    int status = -1;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port (default is 53): ");
    scanf("%d", &port);

    printf("Enter number of attempts (default is 5): ");
    scanf("%d", &attempts);

    for (int i = 0; i < attempts && status == -1; i++)
    {
        struct sockaddr_in sin;
        sin.sin_family = AF_INET;
        sin.sin_port = htons(port);
        sin.sin_addr.s_addr = inet_addr(hostname);

        int sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

        if (sockfd == -1)
        {
            perror("Error creating socket");
            exit(1);
        }

        if (connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) == 0)
        {
            status = 0;
            printf("Connection successful!\n");
            close(sockfd);
        }
        else
        {
            perror("Error connecting");
            attempts++;
        }
    }

    if (status == -1)
    {
        printf("Unable to connect to host.\n");
    }

    return 0;
}