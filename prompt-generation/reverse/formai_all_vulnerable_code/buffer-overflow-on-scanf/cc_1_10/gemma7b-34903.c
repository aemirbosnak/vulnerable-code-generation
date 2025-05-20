//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_PINGS 10
#define TIMEOUT 5

int main()
{
    char *hostname;
    int i, j, k, num_pings, sockfd, ping_status, err;
    struct sockaddr_in servaddr;
    struct hostent *hp;
    char ping_msg[] = "Ping!";
    char recv_msg[1024];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    num_pings = 0;
    ping_status = 0;

    for (i = 0; i < MAX_PINGS; i++)
    {
        sockfd = socket(AF_INET, SOCK_DGRAM, htons(6));

        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(6);
        servaddr.sin_addr.s_addr = inet_addr(hostname);

        sendto(sockfd, ping_msg, strlen(ping_msg), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

        err = recvfrom(sockfd, recv_msg, 1024, 0, (struct sockaddr *)&servaddr, NULL);

        if (err < 0)
        {
            perror("Error receiving ping response");
            ping_status = -1;
        } else
        {
            printf("Received: %s\n", recv_msg);
            num_pings++;
        }

        close(sockfd);
    }

    if (num_pings == MAX_PINGS)
    {
        printf("Number of pings: %d\n", num_pings);
        printf("Ping status: %d\n", ping_status);
    } else
    {
        printf("Error pinging host.\n");
    }

    return 0;
}