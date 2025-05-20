//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int sockfd, ping_status, i, j, k, n_hosts, target_port = 53000;
    char host_list[20][256], buf[1024], msg[1024], hostname[256];
    struct sockaddr_in serv_addr, client_addr;

    // Get the number of hosts from the user
    printf("Enter the number of hosts to ping: ");
    scanf("%d", &n_hosts);

    // Allocate memory for the host list
    for (i = 0; i < n_hosts; i++)
    {
        host_list[i][0] = '\0';
    }

    // Get the host list from the user
    for (i = 0; i < n_hosts; i++)
    {
        printf("Enter the hostname of host %d: ", i + 1);
        scanf("%s", host_list[i]);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(2));

    // Bind the socket to a port
    serv_addr.sin_port = htons(target_port);
    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Send a ping message to each host
    for (i = 0; i < n_hosts; i++)
    {
        // Construct the ping message
        strcpy(msg, "PING");
        strcat(msg, host_list[i]);
        strcat(msg, "\n");

        // Send the ping message
        sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *)host_list[i], sizeof(client_addr));

        // Receive the ping response
        recvfrom(sockfd, buf, 1024, 0, (struct sockaddr *)host_list[i], NULL);

        // Print the ping response
        printf("Host: %s, Response: %s\n", host_list[i], buf);
    }

    // Close the socket
    close(sockfd);

    return 0;
}