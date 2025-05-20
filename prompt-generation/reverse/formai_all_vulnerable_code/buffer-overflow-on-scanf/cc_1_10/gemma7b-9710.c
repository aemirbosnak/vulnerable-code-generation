//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PINGS 5
#define TIMEOUT 2

int main()
{
    int i, j, count = 0, ping_status;
    char host[256];
    struct sockaddr_in sock_addr;
    struct hostent *hp;

    printf("Enter host name: ");
    scanf("%s", host);

    hp = gethostbyname(host);
    sock_addr.sin_family = hp->h_addrtype;
    sock_addr.sin_port = htons(53);
    sock_addr.sin_addr.s_addr = hp->h_addr;

    for (i = 0; i < MAX_PINGS; i++)
    {
        ping_status = ping(&sock_addr, TIMEOUT);
        if (ping_status == 0)
        {
            count++;
            printf("Ping successful!\n");
        }
        else
        {
            printf("Ping failed.\n");
        }

        sleep(1);
    }

    printf("Total number of successful pings: %d\n", count);

    return 0;
}

int ping(struct sockaddr_in *sock_addr, int timeout)
{
    int sockfd, status, bytes_sent, bytes_recv;
    char msg[1024];

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(22));
    if (sockfd < 0)
    {
        return -1;
    }

    memset(msg, 'a', 1024);
    bytes_sent = sendto(sockfd, msg, 1024, 0, (struct sockaddr *)sock_addr, sizeof(*sock_addr));
    if (bytes_sent < 0)
    {
        return -1;
    }

    bytes_recv = recvfrom(sockfd, msg, 1024, 0, (struct sockaddr *)sock_addr, NULL);
    if (bytes_recv < 0)
    {
        return -1;
    }

    close(sockfd);

    if (strcmp(msg, "alive") == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}