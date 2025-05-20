//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT_SCAN_MAX 65535

int main()
{
    int sockfd, target_port, scan_port, num_ports, flags;
    char hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter number of ports to scan: ");
    scanf("%d", &num_ports);

    scan_port = target_port = 1;
    flags = 1;

    while (scan_port <= num_ports)
    {
        if ((sockfd = socket(AF_INET, SOCK_STREAM, htons(scan_port))) == -1)
        {
            perror("Error creating socket");
            flags = 0;
            break;
        }

        if (connect(sockfd, (struct sockaddr *)hostname, sizeof(hostname)) == 0)
        {
            printf("Port %d is open\n", scan_port);
            close(sockfd);
        }

        scan_port++;
    }

    if (flags)
    {
        printf("Scan complete.\n");
    }
    else
    {
        printf("Error scanning ports.\n");
    }

    return 0;
}