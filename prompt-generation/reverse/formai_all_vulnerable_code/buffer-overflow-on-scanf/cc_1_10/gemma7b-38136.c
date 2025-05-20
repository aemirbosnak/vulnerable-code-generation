//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PINGS 10
#define SLEEP_TIME 1

int main()
{
    int i, ping_count = 0, status;
    char host[256];

    printf("Enter the host name: ");
    scanf("%s", host);

    for (i = 0; i < MAX_PINGS; i++)
    {
        status = ping(host);
        if (status == 0)
        {
            printf("Ping successful.\n");
            ping_count++;
        }
        else
        {
            printf("Ping failed.\n");
        }

        sleep(SLEEP_TIME);
    }

    printf("Total number of successful pings: %d\n", ping_count);

    return 0;
}

int ping(char *host)
{
    int sockfd, bytes_sent, bytes_received, status;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_RAW, htons(8));
    if (sockfd < 0)
    {
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(53);
    serv_addr.sin_addr.s_addr = inet_addr(host);

    bytes_sent = sendto(sockfd, "Ping", 5, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (bytes_sent < 0)
    {
        return -1;
    }

    bytes_received = recvfrom(sockfd, "Response", 5, 0, (struct sockaddr *)&serv_addr, NULL);
    if (bytes_received < 0)
    {
        return -1;
    }

    status = 0;
    if (strcmp("Response", "Pong") != 0)
    {
        status = -1;
    }

    close(sockfd);
    return status;
}