//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
    char hostname[256];
    int port;
    int i;
    int status;

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the port number: ");
    scanf("%d", &port);

    for (i = 0; i < 10; i++)
    {
        status = ping(hostname, port);
        if (status == 0)
        {
            printf("Ping successful!\n");
        }
        else
        {
            printf("Ping failed!\n");
        }

        sleep(1);
    }

    return 0;
}

int ping(char *hostname, int port)
{
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[128];
    int bytes_sent, bytes_recv;

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
    if (sockfd < 0)
    {
        return -1;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_aton(hostname, &servaddr.sin_addr);

    bytes_sent = sendto(sockfd, buf, 128, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (bytes_sent < 0)
    {
        return -1;
    }

    bytes_recv = recvfrom(sockfd, buf, 128, 0, (struct sockaddr *)&servaddr, NULL);
    if (bytes_recv < 0)
    {
        return -1;
    }

    close(sockfd);

    return 0;
}