//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_PINGS 10

int main()
{
    int i, j, status, sockfd, port = 8888, retries = MAX_PINGS;
    char host[256], buf[1024], ping_reply[1024];
    struct sockaddr_in servaddr;

    printf("Prepare for the shock of your life!\n");
    printf("Enter the host name: ");
    scanf("%s", host);

    for (i = 0; i < retries; i++)
    {
        sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(port);
        servaddr.sin_addr.s_addr = inet_addr(host);

        sendto(sockfd, "PING", 4, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

        memset(ping_reply, 0, sizeof(ping_reply));
        recvfrom(sockfd, ping_reply, sizeof(ping_reply), 0, (struct sockaddr *)&servaddr, NULL);

        if (strcmp(ping_reply, "PONG") == 0)
        {
            printf("Ping successful!\n");
            status = 0;
            break;
        }
        else
        {
            printf("Error: ping failed.\n");
            sleep(1);
        }
    }

    if (status)
    {
        printf("Sorry, but the ping failed. Please try again.\n");
    }

    return 0;
}