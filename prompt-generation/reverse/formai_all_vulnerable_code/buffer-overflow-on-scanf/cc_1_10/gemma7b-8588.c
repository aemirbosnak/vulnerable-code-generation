//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_PINGS 10
#define TIMEOUT 2

int main()
{
    int sockfd, port, i, status, num_pings = 0;
    char hostname[256];
    struct sockaddr_in serv_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(6));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Get the hostname from the user
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    // Set up the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_aton(hostname, &serv_addr.sin_addr);

    // Send and receive pings
    for (i = 0; i < MAX_PINGS; i++)
    {
        char msg[10] = "Ping!";
        sendto(sockfd, msg, sizeof(msg), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

        char resp[10] = "";
        recvfrom(sockfd, resp, sizeof(resp), 0, (struct sockaddr *)&serv_addr, NULL);

        // Print the ping response
        printf("Ping response: %s\n", resp);

        num_pings++;
    }

    // Print the number of pings
    printf("Number of pings: %d\n", num_pings);

    // Close the socket
    close(sockfd);

    return 0;
}