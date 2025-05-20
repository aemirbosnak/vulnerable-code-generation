//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char hostname[256];
    int port;
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];
    int bytes_sent, bytes_received, i;

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the port: ");
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
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    for (i = 0; i < 10; i++)
    {
        bytes_sent = sendto(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (bytes_sent < 0)
        {
            perror("Error sending data");
            exit(1);
        }

        bytes_received = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, NULL);
        if (bytes_received < 0)
        {
            perror("Error receiving data");
            exit(1);
        }

        printf("Received: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}