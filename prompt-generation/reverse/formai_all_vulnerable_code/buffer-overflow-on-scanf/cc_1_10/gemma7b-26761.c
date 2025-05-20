//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_HOSTS 10

int main()
{
    int i, host_count = 0, sockfd, ping_status = 0, timeout = 5;
    char host_list[MAX_HOSTS][255];
    struct sockaddr_in serv_addr;

    // Get the host list from the user
    printf("Enter the host list (separated by commas): ");
    scanf("%s", host_list[0]);

    // Split the host list into individual hosts
    char *host_ptr = strtok(host_list[0], ",");
    while (host_ptr)
    {
        strcpy(host_list[host_count++], host_ptr);
        host_ptr = strtok(NULL, ",");
    }

    // Create a socket for each host
    for (i = 0; i < host_count; i++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
        serv_addr.sin_port = htons(80);
        serv_addr.sin_addr.s_addr = inet_addr(host_list[i]);

        // Send a ping message and listen for a response
        send(sockfd, "PING", 5, 0);
        if (recv(sockfd, "PONG", 5, 0) == 5)
        {
            ping_status = 1;
            printf("Host %s is online.\n", host_list[i]);
        }
        else
        {
            ping_status = 0;
            printf("Host %s is offline.\n", host_list[i]);
        }

        close(sockfd);
    }

    // Print the overall ping status
    if (ping_status)
    {
        printf("All hosts are online.\n");
    }
    else
    {
        printf("Some hosts are offline.\n");
    }

    return 0;
}