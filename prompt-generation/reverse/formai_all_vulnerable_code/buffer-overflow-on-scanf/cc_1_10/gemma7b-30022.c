//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    int sockfd, port, i, status, timeout = 10;
    char hostname[256];
    struct sockaddr_in servaddr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    port = 5000;
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_aton(hostname, &servaddr.sin_addr);

    status = sendto(sockfd, "ping", 4, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (status == -1)
    {
        perror("Error sending ping");
        exit(1);
    }

    printf("Waiting for reply...\n");
    i = 0;
    while (i < timeout)
    {
        char reply[1024];
        int recvlen = recvfrom(sockfd, reply, 1024, 0, (struct sockaddr *)&servaddr, NULL);

        if (recvlen > 0)
        {
            printf("Reply: %s\n", reply);
            break;
        }

        i++;
        sleep(1);
    }

    if (i == timeout)
    {
        printf("No reply received.\n");
    }

    close(sockfd);
    return 0;
}