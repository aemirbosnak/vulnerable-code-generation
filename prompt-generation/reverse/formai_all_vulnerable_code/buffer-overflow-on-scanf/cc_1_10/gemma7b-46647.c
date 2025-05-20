//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_PORT 65535

int main()
{
    int sockfd, port, n, i;
    char buf[1024];
    struct sockaddr_in servaddr;
    char hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    for (port = 1; port <= MAX_PORT; port++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

        if (sockfd < 0)
        {
            perror("Error creating socket");
            continue;
        }

        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(port);
        servaddr.sin_addr.s_addr = inet_addr(hostname);

        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        {
            perror("Error connecting to socket");
            close(sockfd);
            continue;
        }

        n = read(sockfd, buf, 1024);
        buf[n] = '\0';

        printf("Port: %d, Message: %s\n", port, buf);

        close(sockfd);
    }

    return 0;
}