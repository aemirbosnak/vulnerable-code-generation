//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdlib.h>

#define MAX_PACKET_SIZE 1024

int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX_PACKET_SIZE];
    int bytes_received, total_bytes_received = 0, packets_received = 0;
    clock_t start_time, end_time, total_time = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

    // Bind the socket to a port
    servaddr.sin_port = htons(5000);
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Listen for connections
    connfd = accept(sockfd, (struct sockaddr *)&cliaddr, NULL);

    // Start the clock
    start_time = clock();

    // Receive packets
    while ((bytes_received = recv(connfd, buffer, MAX_PACKET_SIZE, 0)) > 0)
    {
        // Increment the total number of packets received
        packets_received++;

        // Update the total number of bytes received
        total_bytes_received += bytes_received;

        // Measure the end time of the packet
        end_time = clock();

        // Calculate the time taken for the packet to be received
        total_time += end_time - start_time;

        // Start the clock for the next packet
        start_time = clock();
    }

    // Close the connection
    close(connfd);

    // Calculate the average time taken for each packet to be received
    float avg_time = (float)total_time / packets_received;

    // Print the results
    printf("Total number of packets received: %d\n", packets_received);
    printf("Total number of bytes received: %d\n", total_bytes_received);
    printf("Average time taken for each packet to be received: %.2f seconds\n", avg_time);

    return 0;
}