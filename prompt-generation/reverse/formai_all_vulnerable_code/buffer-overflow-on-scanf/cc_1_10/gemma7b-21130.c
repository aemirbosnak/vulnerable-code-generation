//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 1024

int main()
{
    int sockfd, newsockfd, clientlen;
    struct sockaddr_in server_addr, client_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8));

    // Bind the socket to a port
    server_addr.sin_port = htons(5000);
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for connections
    clientlen = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);

    // Send and receive packets
    char packet[MAX_PACKET_SIZE];
    int packets_sent = 0, packets_received = 0;
    while (1)
    {
        // Send a packet
        printf("Enter packet data: ");
        scanf("%s", packet);
        send(newsockfd, packet, MAX_PACKET_SIZE, 0);
        packets_sent++;

        // Receive a packet
        recv(newsockfd, packet, MAX_PACKET_SIZE, 0);
        packets_received++;

        // Print the packet data
        printf("Received packet: %s\n", packet);
    }

    // Close the socket
    close(newsockfd);
    close(sockfd);

    // Print the number of packets sent and received
    printf("Number of packets sent: %d\n", packets_sent);
    printf("Number of packets received: %d\n", packets_received);

    return 0;
}