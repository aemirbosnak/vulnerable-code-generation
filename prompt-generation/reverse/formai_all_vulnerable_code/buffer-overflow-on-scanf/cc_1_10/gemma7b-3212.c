//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: genius
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define PORT_MAX 65535

int main()
{
    int sockfd, port, n, i, buflen = 1024, is_alive = 1;
    char buffer[buflen], hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    for (port = 1; port <= PORT_MAX; port++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
        if (sockfd == -1)
            continue;

        struct sockaddr_in servaddr;
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(port);
        servaddr.sin_addr.s_addr = inet_addr(hostname);

        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
            continue;

        // Send a message and check if the server is alive
        write(sockfd, "HELLO", 6);
        read(sockfd, buffer, buflen);

        if (strcmp(buffer, "HELLO") == 0)
        {
            printf("Port %d is alive.\n", port);
            is_alive = 0;
        }

        close(sockfd);
    }

    if (is_alive)
    {
        printf("No ports are alive.\n");
    }

    return 0;
}