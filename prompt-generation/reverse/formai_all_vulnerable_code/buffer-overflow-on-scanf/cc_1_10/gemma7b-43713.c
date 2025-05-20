//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PINGS 10

int main()
{
    int i, ping_count = 0, status;
    char hostname[256];
    struct sockaddr_in servaddr;
    int sockfd;

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr(hostname);

    for (i = 0; i < MAX_PINGS; i++)
    {
        status = ping(sockfd, servaddr);
        if (status == 0)
        {
            printf("Ping successful.\n");
            ping_count++;
        }
        else
        {
            printf("Ping failed.\n");
        }

        sleep(1);
    }

    printf("Total number of successful pings: %d\n", ping_count);

    close(sockfd);

    return 0;
}

int ping(int sockfd, struct sockaddr_in servaddr)
{
    char buf[1024];
    int bytes_sent, bytes_received, status;

    send(sockfd, buf, 1024, 0);
    bytes_received = recv(sockfd, buf, 1024, 0);

    if (bytes_received > 0)
    {
        status = 0;
    }
    else
    {
        status = 1;
    }

    return status;
}