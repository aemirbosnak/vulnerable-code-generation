//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define NUM_PACKETS 10

int main()
{
    int sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    char packet[MAX_PACKET_SIZE];
    int packet_size;
    int num_packets;
    time_t start_time, end_time;
    double rtt_sum = 0.0;
    double rtt_avg = 0.0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_port = htons(5000);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (client_sockfd < 0)
    {
        perror("Error accepting client connection");
        exit(1);
    }

    // Start the timer
    start_time = time(NULL);

    // Send and receive packets
    num_packets = 0;
    while (num_packets < NUM_PACKETS)
    {
        // Send a packet
        packet_size = write(client_sockfd, packet, MAX_PACKET_SIZE);
        if (packet_size < 0)
        {
            perror("Error sending packet");
            exit(1);
        }

        // Receive a packet
        packet_size = read(client_sockfd, packet, MAX_PACKET_SIZE);
        if (packet_size < 0)
        {
            perror("Error receiving packet");
            exit(1);
        }

        // Calculate the round-trip time (RTT)
        end_time = time(NULL);
        double rtt = (double)(end_time - start_time) * 1000.0;
        start_time = end_time;

        // Add the RTT to the sum
        rtt_sum += rtt;

        // Increment the number of packets
        num_packets++;
    }

    // Stop the timer
    end_time = time(NULL);

    // Calculate the average RTT
    rtt_avg = rtt_sum / num_packets;

    // Print the results
    printf("Number of packets: %d\n", num_packets);
    printf("Average RTT: %.2f ms\n", rtt_avg);

    // Close the socket
    close(sockfd);

    return 0;
}