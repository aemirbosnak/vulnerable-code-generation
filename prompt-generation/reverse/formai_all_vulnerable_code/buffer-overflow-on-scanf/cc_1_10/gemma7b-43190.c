//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HOSTS 1000

int main()
{
    int host_num = 0;
    char host_arr[MAX_HOSTS][256];
    int ping_status[MAX_HOSTS];

    // Get hostnames from the user
    printf("Enter the number of hosts: ");
    scanf("%d", &host_num);

    printf("Enter the hostnames: ");
    for (int i = 0; i < host_num; i++)
    {
        scanf("%s", host_arr[i]);
    }

    // Ping each host
    for (int i = 0; i < host_num; i++)
    {
        ping_status[i] = ping(host_arr[i]);
    }

    // Print the results
    for (int i = 0; i < host_num; i++)
    {
        if (ping_status[i] == 0)
        {
            printf("%s is online.\n", host_arr[i]);
        }
        else
        {
            printf("%s is offline.\n", host_arr[i]);
        }
    }

    return 0;
}

int ping(char *host)
{
    int sockfd, result, bytes_sent, bytes_received;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(8));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(53);
    serv_addr.sin_addr.s_addr = inet_addr(host);

    bytes_sent = sendto(sockfd, "ping", 3, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    bytes_received = recvfrom(sockfd, "pong", 3, 0, (struct sockaddr *)&serv_addr, NULL);

    if (bytes_sent == bytes_received && strcmp("pong", "pong") == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}