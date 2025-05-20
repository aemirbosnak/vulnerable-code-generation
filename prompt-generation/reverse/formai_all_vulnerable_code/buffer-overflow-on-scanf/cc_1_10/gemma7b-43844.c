//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PORTS 1000

int main()
{
    int port;
    char hostname[256];
    struct sockaddr_in sock_addr;
    int sockfd;
    char buf[1024];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    for (port = 1; port <= MAX_PORTS; port++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
        if (sockfd < 0)
        {
            perror("Error creating socket");
            continue;
        }

        sock_addr.sin_family = AF_INET;
        sock_addr.sin_port = htons(port);
        sock_addr.sin_addr.s_addr = inet_addr(hostname);

        if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
        {
            perror("Error connecting to socket");
            close(sockfd);
            continue;
        }

        printf("Port %d: ", port);

        // Send and receive data
        write(sockfd, "Hello, world!", 13);
        read(sockfd, buf, 1024);

        printf("Response: %s\n", buf);

        close(sockfd);
    }

    return 0;
}