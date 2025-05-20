//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define MAX_PINGS 10
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, i, j, k, port, n, count = 0, status;
    char buffer[BUFFER_SIZE], hostname[256];
    struct sockaddr_in serv_addr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port: ");
    scanf("%d", &port);

    for (i = 0; i < MAX_PINGS; i++)
    {
        sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        serv_addr.sin_addr.s_addr = inet_addr(hostname);

        n = sendto(sockfd, "Ping", 5, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

        if (n < 0)
        {
            perror("Error sending ping");
            exit(1);
        }

        count++;

        if (count % 5 == 0)
        {
            printf("Average time: %f seconds\n", (double)status / 5);
            status = 0;
        }

        memset(buffer, 0, BUFFER_SIZE);

        n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&serv_addr, NULL);

        if (n < 0)
        {
            perror("Error receiving ping");
            exit(1);
        }

        status += atoi(buffer);
    }

    return 0;
}