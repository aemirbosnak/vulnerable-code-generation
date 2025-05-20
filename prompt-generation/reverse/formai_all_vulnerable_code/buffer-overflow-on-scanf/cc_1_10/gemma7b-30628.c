//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PINGS 10
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, i, j, ping_count = 0, err_count = 0;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    for (i = 0; i < MAX_PINGS; i++)
    {
        sockfd = socket(AF_INET, SOCK_DGRAM, htons(5));
        if (sockfd < 0)
        {
            err_count++;
            continue;
        }

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(65535);
        server_addr.sin_addr.s_addr = inet_addr(hostname);

        if (sendto(sockfd, "PING", 4, 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        {
            err_count++;
            close(sockfd);
            continue;
        }

        if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, NULL) > 0)
        {
            ping_count++;
            printf("Ping: %d\n", atoi(buffer));
        }

        close(sockfd);
    }

    printf("Number of pings: %d\n", ping_count);
    printf("Number of errors: %d\n", err_count);

    return 0;
}