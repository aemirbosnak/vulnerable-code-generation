//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HOSTS 10

int main()
{
    char hostnames[MAX_HOSTS][256];
    int num_hosts = 0;

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    if (num_hosts > MAX_HOSTS)
    {
        printf("Error: Too many hosts.\n");
        return 1;
    }

    for (int i = 0; i < num_hosts; i++)
    {
        printf("Enter the hostname of host %d: ", i + 1);
        scanf("%s", hostnames[i]);
    }

    for (int i = 0; i < num_hosts; i++)
    {
        int sockfd = socket(AF_INET, SOCK_DGRAM, htons(5));
        struct sockaddr_in servaddr;

        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(1234);
        servaddr.sin_addr.s_addr = inet_addr(hostnames[i]);

        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
        {
            printf("Error: Unable to connect to host %s.\n", hostnames[i]);
        }
        else
        {
            printf("Host %s is alive.\n", hostnames[i]);
        }

        close(sockfd);
    }

    return 0;
}