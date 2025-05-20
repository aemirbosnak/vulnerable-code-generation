//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: careful
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PINGS 5
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, port, i, status;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    for (i = 0; i < MAX_PINGS; i++)
    {
        sendto(sockfd, "Ping", 5, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        memset(buffer, 0, BUFFER_SIZE);

        status = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, NULL);

        if (status > 0)
        {
            printf("Received: %s\n", buffer);
        }
        else
        {
            perror("Error receiving message");
            exit(1);
        }
    }

    close(sockfd);

    return 0;
}