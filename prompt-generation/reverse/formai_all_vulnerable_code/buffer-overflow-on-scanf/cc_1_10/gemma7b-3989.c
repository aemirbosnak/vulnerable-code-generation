//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_PINGS 10
#define BUFFER_SIZE 1024

int main()
{
    char hostname[256];
    int i, j, k, l, port, sockfd, flags, status, bytes_sent, bytes_received;
    struct sockaddr_in servaddr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    for (i = 0; i < MAX_PINGS; i++)
    {
        printf("Pinging... ");

        // Create a socket
        sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));

        // Set up the server address
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(port);
        inet_pton(AF_INET, hostname, &servaddr.sin_addr);

        // Send a ping message
        char message[BUFFER_SIZE] = "PING!";
        bytes_sent = sendto(sockfd, message, BUFFER_SIZE, flags, (struct sockaddr *)&servaddr, sizeof(servaddr));

        // Receive the ping response
        char response[BUFFER_SIZE];
        bytes_received = recvfrom(sockfd, response, BUFFER_SIZE, flags, (struct sockaddr *)&servaddr, NULL);

        // Check if the ping was successful
        status = strcmp(response, "PONG!");
        if (status == 0)
        {
            printf("Ping successful.\n");
        }
        else
        {
            printf("Ping failed.\n");
        }

        // Close the socket
        close(sockfd);
    }

    return 0;
}