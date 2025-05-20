//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: all-encompassing
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
    char host[256];
    int port;
    int sockfd, i, num_pings = 0, send_bytes, recv_bytes;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    printf("Enter host name: ");
    scanf("%s", host);

    printf("Enter port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    for (i = 0; i < MAX_PINGS; i++)
    {
        send_bytes = sendto(sockfd, "PING", 4, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (send_bytes < 0)
        {
            perror("Error sending ping");
            exit(1);
        }

        recv_bytes = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, NULL);
        if (recv_bytes < 0)
        {
            perror("Error receiving ping");
            exit(1);
        }

        printf("Ping %d: Response: %s\n", num_pings, buffer);
        num_pings++;
    }

    close(sockfd);
    return 0;
}