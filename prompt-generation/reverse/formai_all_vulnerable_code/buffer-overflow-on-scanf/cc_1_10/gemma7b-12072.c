//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_PINGS 10

int main()
{
    int sockfd, port, i, j, k, success = 0;
    char host[256], ping_message[128], received_message[128];

    printf("Enter the host name: ");
    scanf("%s", host);

    printf("Enter the port number: ");
    scanf("%d", &port);

    for (i = 0; i < MAX_PINGS; i++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
        if (sockfd < 0)
        {
            perror("Error creating socket");
            exit(1);
        }

        ping_message[0] = 'P';
        ping_message[1] = 'I';
        ping_message[2] = 'N';
        ping_message[3] = 'G';
        ping_message[4] = '\0';

        if (send(sockfd, ping_message, sizeof(ping_message), 0) < 0)
        {
            perror("Error sending ping message");
            close(sockfd);
            continue;
        }

        j = recv(sockfd, received_message, sizeof(received_message), 0);
        if (j > 0)
        {
            received_message[j] = '\0';
            printf("Received: %s\n", received_message);

            if (strcmp(received_message, "Alive") == 0)
            {
                success = 1;
            }
        }

        close(sockfd);
    }

    if (success)
    {
        printf("Host is alive!\n");
    }
    else
    {
        printf("Host is not alive.\n");
    }

    return 0;
}