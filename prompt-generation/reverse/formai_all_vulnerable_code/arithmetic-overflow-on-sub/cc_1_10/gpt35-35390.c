//FormAI DATASET v1.0 Category: Network Ping Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

// Define the packet size in bytes
#define PACKET_SIZE 64

// Define the number of packets to send
#define NUM_PACKETS 10

// Define the delay between packets in microseconds
#define PACKET_DELAY 1000000

// Function to calculate the time difference in microseconds
long long int microsecond_difference(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

// Function to calculate the round trip time
long long int round_trip_time(struct timeval sent_time, struct timeval received_time) {
    return microsecond_difference(sent_time, received_time);
}

int main(int argc, char *argv[]) {

    int sockfd;
    struct sockaddr_in server_addr;
    struct timeval sent_time, received_time;

    // Check for the correct number of arguments
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 0;
    }

    // Create a socket for sending and receiving datagrams
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Could not bind socket\n");
        return 0;
    }

    // Configure server address for sending
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(0);

    // Declare variables for tracking statistics
    long long int total_rtt = 0, min_rtt = 0, max_rtt = 0;
    int num_received = 0;

    // Iterate over the specified number of packets
    for (int i = 1; i <= NUM_PACKETS; i++) {

        // Create a buffer for the packet data
        char buffer[PACKET_SIZE];

        // Record the time the packet is sent
        gettimeofday(&sent_time, NULL);

        // Send the packet to the server
        if (sendto(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            printf("Error sending packet %d\n", i);
            continue;
        }

        // Wait for the packet to be returned
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        if (select(sockfd + 1, &readfds, NULL, NULL, &timeout) == 1) {

            // Receive the packet
            char recv_buffer[PACKET_SIZE];
            struct sockaddr_in server_recv_addr;
            socklen_t server_recv_len = sizeof(server_recv_addr);
            if (recvfrom(sockfd, recv_buffer, PACKET_SIZE, 0, (struct sockaddr *)&server_recv_addr, &server_recv_len) < 0) {
                printf("Error receiving packet %d\n", i);
                continue;
            }

            // Record the time the packet is received
            gettimeofday(&received_time, NULL);

            // Calculate the round trip time
            long long int rtt = round_trip_time(sent_time, received_time);

            // Update the statistics
            total_rtt += rtt;
            num_received++;
            if (min_rtt == 0 || rtt < min_rtt) {
                min_rtt = rtt;
            }
            if (rtt > max_rtt) {
                max_rtt = rtt;
            }

            // Output the results for this packet
            printf("PING %d: %lld us RTT\n", i, rtt);

        } else {
            printf("PING %d: timed out\n", i);
        }

        // Wait before sending the next packet
        usleep(PACKET_DELAY);

    }

    // Calculate and output overall statistics
    if (num_received > 0) {
        printf("--- %s ping statistics ---\n", argv[1]);
        printf("%d packets transmitted, %d received, %d%% packet loss, average %lld us\n", NUM_PACKETS, num_received, (NUM_PACKETS - num_received) * 10, total_rtt / num_received);
        printf("rtt min/avg/max = %lld/%lld/%lld us\n", min_rtt, total_rtt / num_received, max_rtt);
    } else {
        printf("No packets received\n");
    }

    // Close the socket
    close(sockfd);

    return 0;
}