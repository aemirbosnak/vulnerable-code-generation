//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define PORT_RANGE 1024

int main()
{
    int port;
    char hostname[256];
    struct sockaddr_in sock_addr;
    int sockfd, i, n;
    char buffer[1024];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    for (port = 1; port <= PORT_RANGE; port++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
        if (sockfd < 0)
        {
            perror("Error creating socket");
            continue;
        }

        memset(&sock_addr, 0, sizeof(sock_addr));
        sock_addr.sin_family = AF_INET;
        sock_addr.sin_port = htons(port);
        sock_addr.sin_addr.s_addr = inet_addr(hostname);

        if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
        {
            perror("Error connecting to port");
            close(sockfd);
            continue;
        }

        n = read(sockfd, buffer, 1024);
        if (n > 0)
        {
            printf("Port %d: Received data: %s\n", port, buffer);
        }

        close(sockfd);
    }

    return 0;
}