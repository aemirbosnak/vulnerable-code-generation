//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PORT 65535

int main()
{
    int port;
    char hostname[256];
    struct sockaddr_in sock_addr;
    int sockfd;
    char buffer[4096];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    for (port = 1; port <= MAX_PORT; port++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
        if (sockfd == -1)
        {
            continue;
        }

        sock_addr.sin_port = htons(port);
        sock_addr.sin_family = AF_INET;
        strcpy(sock_addr.sin_addr.s_addr, hostname);

        if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1)
        {
            close(sockfd);
            continue;
        }

        printf("Port %d: ", port);

        // Send and receive data
        write(sockfd, "Hello, world!", 13);
        read(sockfd, buffer, 4096);

        printf("Response: %s\n", buffer);

        close(sockfd);
    }

    return 0;
}