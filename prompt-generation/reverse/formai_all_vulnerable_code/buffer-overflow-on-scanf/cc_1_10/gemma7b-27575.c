//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_PINGS 10

int main()
{
    int i, port, status, attempts = 0;
    char hostname[256];
    struct sockaddr_in server_addr;
    FILE *fp;

    system("clear");

    printf("Enter hostname: ");
    scanf("%s", hostname);

    fp = fopen("ping_results.txt", "w");

    for (i = 0; i < MAX_PINGS; i++)
    {
        port = 8080 + i;
        server_addr.sin_port = htons(port);
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(hostname);

        status = ping(&server_addr);

        if (status == 0)
        {
            fprintf(fp, "Ping to %s on port %d successful.\n", hostname, port);
        }
        else
        {
            fprintf(fp, "Ping to %s on port %d failed.\n", hostname, port);
            attempts++;
        }

        if (attempts == MAX_PINGS)
        {
            printf("All pings failed. Please check the hostname or network connection.\n");
            break;
        }
    }

    fclose(fp);

    return 0;
}

int ping(struct sockaddr_in *server_addr)
{
    int sockfd, bytes_sent, bytes_received, status;
    char message[1024];

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(8));

    if (sockfd == -1)
    {
        return -1;
    }

    strcpy(message, "Ping!");

    bytes_sent = sendto(sockfd, message, sizeof(message), 0, (struct sockaddr *)server_addr, sizeof(*server_addr));

    if (bytes_sent == -1)
    {
        return -1;
    }

    bytes_received = recvfrom(sockfd, message, sizeof(message), 0, (struct sockaddr *)server_addr, NULL);

    if (bytes_received == -1)
    {
        return -1;
    }

    status = 0;

    if (strcmp(message, "Pong!") == 0)
    {
        status = 0;
    }
    else
    {
        status = -1;
    }

    close(sockfd);

    return status;
}