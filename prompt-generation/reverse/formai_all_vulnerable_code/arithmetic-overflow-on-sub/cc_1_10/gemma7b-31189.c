//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

int main() {

    int sockfd, port, n, bytes_sent, bytes_received;
    struct sockaddr_in servaddr;
    struct sockaddr_in clientaddr;
    char buffer[MAX_PACKET_SIZE];
    time_t start_time, end_time;
    double elapsed_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(6));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    servaddr.sin_port = htons(5000);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    while (1) {
        // Get the client's address and port number
        clientaddr.sin_port = htons(0);
        bytes_received = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&clientaddr, NULL);

        // Start the timer
        start_time = time(NULL);

        // Send a packet back to the client
        bytes_sent = sendto(sockfd, buffer, bytes_received, 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));

        // End the timer
        end_time = time(NULL);

        // Calculate the elapsed time
        elapsed_time = (double)(end_time - start_time) * CLOCKS_PER_SEC;

        // Print the elapsed time
        printf("Elapsed time: %.3f seconds\n", elapsed_time);
    }

    return 0;
}