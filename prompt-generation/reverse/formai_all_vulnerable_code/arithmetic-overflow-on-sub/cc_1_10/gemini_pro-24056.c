//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define MAX_NUM_PACKETS 10000

int main() {
    // Initialize variables
    int sockfd, n, i, j;
    struct sockaddr_in servaddr;
    struct timeval start, end;
    double elapsed_time;
    char buffer[MAX_PACKET_SIZE];

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(5000);

    // Start the QoS monitor
    printf("Starting QoS monitor...\n");
    for (i = 0; i < MAX_NUM_PACKETS; i++) {
        // Send a packet to the server
        n = sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &servaddr, sizeof(servaddr));
        if (n == -1) {
            perror("sendto");
            exit(EXIT_FAILURE);
        }

        // Start the timer
        gettimeofday(&start, NULL);

        // Receive a packet from the server
        n = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (n == -1) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        // Stop the timer
        gettimeofday(&end, NULL);

        // Calculate the elapsed time
        elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

        // Print the QoS metrics
        printf("Packet %d: RTT = %f ms\n", i, elapsed_time);
    }

    // Close the socket
    close(sockfd);

    return 0;
}