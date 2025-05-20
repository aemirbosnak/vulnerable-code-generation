//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PINGS 10

int main()
{
    int i, pings = 0, status;
    char hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    for (i = 0; i < MAX_PINGS && pings < 1; i++)
    {
        status = ping(hostname);
        if (status == 0)
        {
            printf("Ping successful!\n");
            pings++;
        }
        else
        {
            printf("Ping failed.\n");
        }
    }

    if (pings == MAX_PINGS)
    {
        printf("All pings failed.\n");
    }

    return 0;
}

int ping(char *hostname)
{
    int sockfd, ping_size, status;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(1));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(53);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);

    ping_size = sendto(sockfd, "Ping", 5, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    status = recvfrom(sockfd, "Reply", 5, 0, (struct sockaddr *)&serv_addr, NULL);

    close(sockfd);

    if (status == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}