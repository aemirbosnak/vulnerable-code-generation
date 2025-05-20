//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_PINGS 5
#define TIMEOUT 2

int main()
{
    int i, sockfd, port = 50001, status, numPings = 0;
    char hostname[256];
    struct sockaddr_in servaddr;

    // Get the hostname from the user
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    servaddr.sin_port = htons(port);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(hostname);
    status = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (status < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send and receive pings
    for (i = 0; i < MAX_PINGS; i++)
    {
        printf("Pinging... ");
        send(sockfd, "PING", 5, 0);
        sleep(TIMEOUT);
        char reply[1024];
        recv(sockfd, reply, 1024, 0);
        printf("Reply: %s\n", reply);
        numPings++;
    }

    // Print the number of pings
    printf("Number of pings: %d\n", numPings);

    // Close the socket
    close(sockfd);

    return 0;
}