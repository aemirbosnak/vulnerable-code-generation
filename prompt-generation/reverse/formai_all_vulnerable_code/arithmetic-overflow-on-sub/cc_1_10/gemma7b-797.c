//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

int main() {
    int sockfd, sin_port, len, i, packet_size;
    struct sockaddr_in sin;
    char buffer[MAX_PACKET_SIZE];
    time_t start_time, end_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(65535));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    sin.sin_port = htons(8888);
    if (bind(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for packets
    while (1) {
        len = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&sin, NULL);
        if (len < 0) {
            perror("Error receiving packet");
            exit(1);
        }

        // Start the timer
        start_time = time(NULL);

        // Send the packet back
        packet_size = sendto(sockfd, buffer, len, 0, (struct sockaddr *)&sin, sizeof(sin));
        if (packet_size < 0) {
            perror("Error sending packet");
            exit(1);
        }

        // End the timer
        end_time = time(NULL);

        // Calculate the delay
        int delay = end_time - start_time;

        // Print the delay
        printf("Packet delay: %d milliseconds\n", delay);
    }

    return 0;
}