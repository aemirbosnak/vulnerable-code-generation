//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HOSTS 1000

int main()
{
    int host_count = 0;
    char host_list[MAX_HOSTS][256];

    // Get the host list from the user
    printf("Enter a list of hosts, separated by commas: ");
    scanf("%s", host_list[0]);

    // Split the host list into individual hosts
    char *host_ptr = strtok(host_list[0], ",");
    while (host_ptr)
    {
        strcpy(host_list[host_count++], host_ptr);
        host_ptr = strtok(NULL, ",");
    }

    // Ping each host
    for (int i = 0; i < host_count; i++)
    {
        int sockfd;
        struct sockaddr_in sock_addr;

        // Create a socket
        sockfd = socket(AF_INET, SOCK_DGRAM, htons(8));

        // Connect to the host
        sock_addr.sin_family = AF_INET;
        sock_addr.sin_port = htons(53);
        sock_addr.sin_addr.s_addr = inet_addr(host_list[i]);

        // Send a ping message
        char ping_msg[] = "PING!";
        sendto(sockfd, ping_msg, sizeof(ping_msg), 0, (struct sockaddr *)&sock_addr, sizeof(sock_addr));

        // Receive the reply
        char reply_msg[256];
        recvfrom(sockfd, reply_msg, sizeof(reply_msg), 0, (struct sockaddr *)&sock_addr, NULL);

        // Print the reply
        printf("%s: %s\n", host_list[i], reply_msg);
    }

    return 0;
}