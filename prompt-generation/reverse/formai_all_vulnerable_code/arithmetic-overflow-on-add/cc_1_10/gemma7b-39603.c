//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

#define MAX_PORTS 1024

int main()
{
    char host[256];
    int port_start, port_end, port, i, num_open_ports = 0;
    struct sockaddr_in sock_addr;
    int sockfd, result;

    printf("Enter host: ");
    scanf("%s", host);

    printf("Enter port start: ");
    scanf("%d", &port_start);

    printf("Enter port end: ");
    scanf("%d", &port_end);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(8));

    for (port = port_start; port <= port_end; port++)
    {
        sock_addr.sin_family = AF_INET;
        sock_addr.sin_port = htons(port);
        sock_addr.sin_addr.s_addr = inet_addr(host);

        result = connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));

        if (result == 0)
        {
            num_open_ports++;
            printf("Port %d is open.\n", port);
        }
    }

    printf("\nTotal number of open ports: %d\n", num_open_ports);

    for (i = 0; i < num_open_ports; i++)
    {
        printf("Port %d is vulnerable.\n", port_start + i);
    }

    close(sockfd);

    return 0;
}