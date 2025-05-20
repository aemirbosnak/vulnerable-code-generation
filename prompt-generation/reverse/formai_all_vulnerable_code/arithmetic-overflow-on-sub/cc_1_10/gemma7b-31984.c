//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define LISTEN_PORT 5000

int main() {

    int sockfd, newsockfd, clientlen;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX_PACKET_SIZE];
    int received_bytes, total_received_bytes = 0, packets_received = 0;
    time_t start_time, end_time, elapsed_time;
    double avg_packet_size, avg_delay, jitter;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(LISTEN_PORT));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(LISTEN_PORT);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    while (1) {
        // Accept a client connection
        clientlen = sizeof(cliaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clientlen);
        if (newsockfd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Start the timer
        start_time = time(NULL);

        // Receive data
        received_bytes = recv(newsockfd, buffer, MAX_PACKET_SIZE, 0);
        if (received_bytes < 0) {
            perror("Error receiving data");
            close(newsockfd);
            continue;
        }

        // End the timer
        end_time = time(NULL);

        // Calculate the elapsed time
        elapsed_time = end_time - start_time;

        // Calculate the packet size
        packets_received++;
        total_received_bytes += received_bytes;

        // Calculate the average packet size
        avg_packet_size = (double)total_received_bytes / packets_received;

        // Calculate the average delay
        avg_delay = (double)elapsed_time * 1000 / packets_received;

        // Calculate the jitter
        jitter = (double)elapsed_time * 1000 / packets_received - avg_delay;

        // Print the results
        printf("Client IP: %s\n", inet_ntoa(cliaddr.sin_addr));
        printf("Total bytes received: %d\n", total_received_bytes);
        printf("Number of packets received: %d\n", packets_received);
        printf("Average packet size: %.2f bytes\n", avg_packet_size);
        printf("Average delay: %.2f ms\n", avg_delay);
        printf("Jitter: %.2f ms\n", jitter);

        // Close the connection
        close(newsockfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}