//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
    char ping_host[256];
    int ping_port = 53;
    int sockfd, err, bytes_sent, bytes_received;
    struct sockaddr_in serv_addr;

    printf("Enter the host name: ");
    scanf("%s", ping_host);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(ping_port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(ping_port);
    serv_addr.sin_addr.s_addr = inet_addr(ping_host);

    // Send a ping message
    bytes_sent = sendto(sockfd, "PING", 5, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (bytes_sent < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    // Receive a response
    bytes_received = recvfrom(sockfd, ping_host, 256, 0, (struct sockaddr *)&serv_addr, NULL);
    if (bytes_received < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    // Print the response
    printf("Received: %s\n", ping_host);

    // Close the socket
    close(sockfd);

    return 0;
}