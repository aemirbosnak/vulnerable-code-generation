//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

#define PORT_MIN 0
#define PORT_MAX 65535

int main()
{
    int port, n, i;
    char hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter number of ports to scan: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        port = rand() % (PORT_MAX - PORT_MIN + 1) + PORT_MIN;

        if (check_port(hostname, port) == 0)
        {
            printf("Port %d is open.\n", port);
        }
    }

    return 0;
}

int check_port(char *hostname, int port)
{
    int sockfd;
    struct sockaddr_in sock_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    if (sockfd == -1)
    {
        return -1;
    }

    memset(&sock_addr, 0, sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1)
    {
        close(sockfd);
        return -1;
    }

    close(sockfd);
    return 0;
}