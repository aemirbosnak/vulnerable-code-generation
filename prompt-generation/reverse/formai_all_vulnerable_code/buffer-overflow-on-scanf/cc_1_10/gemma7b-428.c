//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PINGS 10
#define SERVER_PORT 8080

int main()
{
    int sockfd, i, j, err, numPings = 0;
    char hostname[256];
    struct sockaddr_in servaddr;

    // Get the hostname from the user
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    servaddr.sin_addr.s_addr = inet_addr(hostname);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send and receive pings
    for (i = 0; i < MAX_PINGS; i++)
    {
        // Send a ping
        write(sockfd, "PING", 5);

        // Receive a pong
        char resp[1024];
        read(sockfd, resp, 1024);

        // Print the pong
        printf("Pong: %s\n", resp);

        // Increment the number of pings
        numPings++;
    }

    // Close the socket
    close(sockfd);

    // Print the number of pings
    printf("Number of pings: %d\n", numPings);

    return 0;
}