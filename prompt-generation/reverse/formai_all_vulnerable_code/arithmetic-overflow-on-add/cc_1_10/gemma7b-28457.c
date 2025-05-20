//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd, clientlen;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[BUFFER_SIZE];
    time_t start, end;
    int packet_loss = 0, total_packets = 0, bytes_received = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    servaddr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    clientlen = sizeof(cliaddr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clientlen);
    if (newsockfd < 0)
    {
        perror("Error accepting client");
        exit(1);
    }

    // Start the timer
    start = time(NULL);

    // Receive packets
    while (1)
    {
        // Receive a packet
        int bytes_received = recv(newsockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0)
        {
            perror("Error receiving packet");
            break;
        }

        // Increment total packets and bytes received
        total_packets++;
        bytes_received += bytes_received;
    }

    // End the timer
    end = time(NULL);

    // Calculate packet loss
    packet_loss = (total_packets - bytes_received) * 100 / total_packets;

    // Print the results
    printf("Client IP: %s\n", cliaddr.sin_addr.s_addr);
    printf("Total packets received: %d\n", total_packets);
    printf("Total bytes received: %d\n", bytes_received);
    printf("Packet loss: %d%%\n", packet_loss);
    printf("Time taken: %ld seconds\n", end - start);

    // Close the socket
    close(newsockfd);
    close(sockfd);

    return 0;
}