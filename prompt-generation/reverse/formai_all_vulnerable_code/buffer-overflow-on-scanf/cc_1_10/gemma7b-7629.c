//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT_SCAN_MAX 65535

int main()
{
    int sockfd, port, nscan, target_port, sr, port_status;
    char hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter number of ports to scan: ");
    scanf("%d", &nscan);

    for (port = 0; port < nscan; port++)
    {
        target_port = port + 1;
        sockfd = socket(AF_INET, SOCK_STREAM, htons(target_port));

        if (sockfd < 0)
        {
            perror("Error creating socket");
            continue;
        }

        sr = send(sockfd, "TEST", 5, 0);

        if (sr < 0)
        {
            perror("Error sending data");
            close(sockfd);
            continue;
        }

        port_status = recv(sockfd, &port_status, sizeof(port_status), 0);

        if (port_status)
        {
            printf("Port %d is open.\n", target_port);
        }
        else
        {
            printf("Port %d is closed.\n", target_port);
        }

        close(sockfd);
    }

    return 0;
}