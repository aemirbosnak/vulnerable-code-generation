//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: artistic
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

#define MAX_PINGS 10
#define PING_DELAY 500

int main()
{
    int i, j, ping_count = 0, success_count = 0;
    char host[256];
    struct sockaddr_in server_addr;
    int sockfd, result;

    printf("Enter the host name: ");
    scanf("%s", host);

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(5));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(6);
    server_addr.sin_addr.s_addr = inet_addr(host);

    for (i = 0; i < MAX_PINGS; i++)
    {
        ping_count++;
        result = sendto(sockfd, "PING", 5, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (result == -1)
        {
            perror("Error sending ping");
            break;
        }

        sleep(PING_DELAY);

        result = recvfrom(sockfd, host, 256, 0, (struct sockaddr *)&server_addr, NULL);
        if (result == -1)
        {
            perror("Error receiving ping");
            break;
        }

        if (strcmp(host, "PING") == 0)
        {
            success_count++;
            printf("Ping successful! Round trip time: %d milliseconds\n", ping_count);
        }
    }

    printf("Overall success rate: %d%% (%d/%d)\n", (success_count * 100) / ping_count, success_count, ping_count);

    return 0;
}