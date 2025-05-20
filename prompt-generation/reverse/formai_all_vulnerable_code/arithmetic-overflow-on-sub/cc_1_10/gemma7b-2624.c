//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 5000
#define MAX_PACKET_SIZE 1024

int main() {

    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_PACKET_SIZE];
    int packet_size;
    int num_packets = 0;
    time_t start_time, end_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(SERVER_PORT));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Start the timer
    start_time = time(NULL);

    // Send and receive packets
    while (num_packets < 10) {
        // Send a packet
        packet_size = sendto(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (packet_size < 0) {
            perror("Error sending packet");
            exit(1);
        }

        // Receive a packet
        packet_size = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&server_addr, NULL);
        if (packet_size < 0) {
            perror("Error receiving packet");
            exit(1);
        }

        num_packets++;
    }

    // End the timer
    end_time = time(NULL);

    // Calculate the time taken
    int time_taken = end_time - start_time;

    // Print the results
    printf("Number of packets sent: %d\n", num_packets);
    printf("Time taken: %d seconds\n", time_taken);
    printf("Average packet delay: %.2f milliseconds\n", (time_taken * 1000.0) / num_packets);

    return 0;
}