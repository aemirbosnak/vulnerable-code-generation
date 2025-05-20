//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: lively
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PINGS 10
#define PING_INTERVAL 1

int main()
{
    int i, j, k, ping_count = 0, status;
    char hostname[256];
    struct sockaddr_in serv_addr;
    struct hostent *hp;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    hp = gethostbyname(hostname);
    if (hp == NULL)
    {
        printf("Error getting host information.\n");
        exit(1);
    }

    serv_addr.sin_family = hp->h_addrtype;
    serv_addr.sin_port = htons(5000);
    serv_addr.sin_addr.s_addr = inet_addr(hp->h_addr);

    for (i = 0; i < MAX_PINGS; i++)
    {
        status = ping(serv_addr, PING_INTERVAL);
        if (status == 0)
        {
            printf("Ping successful.\n");
            ping_count++;
        }
        else
        {
            printf("Ping failed.\n");
        }

        sleep(PING_INTERVAL);
    }

    printf("Total number of successful pings: %d\n", ping_count);

    return 0;
}

int ping(struct sockaddr_in serv_addr, int interval)
{
    int sockfd, bytes_sent, bytes_received, status;
    char message[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0)
    {
        return -1;
    }

    memset(message, 'a', 1024);
    bytes_sent = sendto(sockfd, message, 1024, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (bytes_sent < 0)
    {
        return -1;
    }

    memset(message, 0, 1024);
    bytes_received = recvfrom(sockfd, message, 1024, 0, (struct sockaddr *)&serv_addr, NULL);
    if (bytes_received < 0)
    {
        return -1;
    }

    status = 0;
    if (strcmp(message, "pong") == 0)
    {
        status = 0;
    }
    else
    {
        status = -1;
    }

    close(sockfd);
    return status;
}