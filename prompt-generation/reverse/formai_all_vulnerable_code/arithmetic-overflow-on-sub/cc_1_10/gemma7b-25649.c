//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: optimized
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

int main() {

    // Create a UDP socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, htons(5000));

    // Bind the socket to a port
    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(5000);
    bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));

    // Listen for incoming packets
    char packet[MAX_PACKET_SIZE];
    int recv_len;
    while (1) {
        // Receive a packet
        recv_len = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, NULL, NULL);

        // Check the packet size
        if (recv_len < MAX_PACKET_SIZE) {
            printf("Received packet of size: %d\n", recv_len);
        } else {
            printf("Error: packet size too large\n");
        }

        // Calculate the packet delay
        time_t start_time = time(NULL);
        time_t end_time = time(NULL);
        while (end_time - start_time < 5) {
            end_time = time(NULL);
        }
        int delay = end_time - start_time;

        // Print the packet delay
        printf("Packet delay: %d milliseconds\n", delay);
    }

    // Close the socket
    close(sockfd);

    return 0;
}