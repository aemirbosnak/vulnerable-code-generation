//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    int i, sockfd, n, ping_status = 0;
    char hostname[256];
    struct sockaddr_in servaddr;

    // Get the hostname from the user
    printf("Enter the hostname of the server: ");
    scanf("%s", hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(6));

    // Connect to the server
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6);
    servaddr.sin_addr.s_addr = inet_addr(hostname);
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Send a ping message
    char ping_message[] = "Ping!";
    send(sockfd, ping_message, sizeof(ping_message), 0);

    // Receive the ping response
    char response[256];
    n = recv(sockfd, response, sizeof(response), 0);

    // Check if the ping was successful
    if (strcmp(response, "Pong!") == 0)
    {
        ping_status = 1;
    }

    // Close the socket
    close(sockfd);

    // Print the ping status
    if (ping_status)
    {
        printf("Ping successful!\n");
    }
    else
    {
        printf("Ping failed.\n");
    }

    return 0;
}