//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PINGS 10

int main()
{
    int i, sockfd, port, status, err;
    char host[256];
    struct sockaddr_in serv_addr;

    // Get host name from user
    printf("Enter the host name: ");
    scanf("%s", host);

    // Get port number from user
    printf("Enter the port number: ");
    scanf("%d", &port);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_aton(host, &serv_addr.sin_addr);

    // Send ping requests
    for (i = 0; i < MAX_PINGS; i++)
    {
        char msg[] = "PING!";
        sendto(sockfd, msg, sizeof(msg), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

        // Receive the ping response
        char resp[1024];
        recvfrom(sockfd, resp, sizeof(resp), 0, (struct sockaddr *)&serv_addr, NULL);

        // Print the ping response
        printf("Received ping response: %s\n", resp);
    }

    // Close the socket
    close(sockfd);

    return 0;
}