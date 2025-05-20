//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define PORT_RANGE 1024

int main()
{
    int sockfd, port, n, i, host_port;
    char hostname[256];
    struct sockaddr_in serv_addr;

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the port range: ");
    scanf("%d", &port);

    for (i = port; i < port + PORT_RANGE; i++)
    {
        serv_addr.sin_port = htons(i);
        sockfd = socket(AF_INET, SOCK_STREAM, htons(6));

        if (sockfd == -1)
        {
            perror("Error creating socket");
            exit(1);
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_aton(hostname, NULL);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        {
            perror("Error connecting to server");
            close(sockfd);
            continue;
        }

        n = write(sockfd, "Hello, world!", 13);
        if (n == -1)
        {
            perror("Error writing to socket");
            close(sockfd);
            continue;
        }

        n = read(sockfd, hostname, 256);
        if (n == -1)
        {
            perror("Error reading from socket");
            close(sockfd);
            continue;
        }

        printf("Host: %s\n", hostname);
        close(sockfd);
    }

    return 0;
}