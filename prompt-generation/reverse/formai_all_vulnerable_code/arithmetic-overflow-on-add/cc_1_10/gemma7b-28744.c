//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define PORT_SCAN_MAX 65535

int main()
{
    char host[256];
    int port;
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[1024];

    printf("Enter host name: ");
    scanf("%s", host);

    printf("Enter port range (separated by -): ");
    scanf("%d-%d", &port, &port);

    for (port = port; port <= port; port++)
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
        servaddr.sin_addr.s_addr = inet_addr(host);

        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        {
            perror("Error connecting to socket");
            close(sockfd);
            continue;
        }

        printf("Port %d: ", port);

        if (read(sockfd, buf, 1024) > 0)
        {
            printf("Response: %s\n", buf);
        } else
        {
            printf("No response\n");
        }

        close(sockfd);
    }

    return 0;
}