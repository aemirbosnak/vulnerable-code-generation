//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    int sockfd, port, i, n, flag = 0;
    char buffer[1024];

    printf("Enter the target port: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    printf("Scanning port %d...", port);

    for (i = 0; i < 10; i++)
    {
        n = send(sockfd, "test", 5, 0);
        if (n < 0)
        {
            perror("Error sending data");
            exit(1);
        }

        memset(buffer, 0, 1024);

        n = recv(sockfd, buffer, 1024, 0);
        if (n > 0)
        {
            printf("Port %d is open.\n", port);
            flag = 1;
        }
    }

    if (flag == 0)
    {
        printf("Port %d is closed.\n", port);
    }

    close(sockfd);

    return 0;
}