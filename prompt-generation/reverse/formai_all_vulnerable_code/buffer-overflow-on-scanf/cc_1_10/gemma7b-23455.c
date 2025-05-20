//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PINGS 10

int main()
{
    int i, sockfd, port, err, num_pings = 0;
    char hostname[256];
    struct sockaddr_in serv_addr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    port = 5000;

    for (i = 0; i < MAX_PINGS; i++)
    {
        sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        serv_addr.sin_addr.s_addr = inet_addr(hostname);

        err = sendto(sockfd, "ping", 4, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        if (err < 0)
        {
            perror("Error sending ping");
            break;
        }

        sleep(1);

        err = recvfrom(sockfd, hostname, 256, 0, (struct sockaddr *)&serv_addr, NULL);
        if (err < 0)
        {
            perror("Error receiving ping");
            break;
        }

        printf("Ping: %s\n", hostname);
        num_pings++;
    }

    printf("Number of pings: %d\n", num_pings);

    return 0;
}