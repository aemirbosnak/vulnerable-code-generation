//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <signal.h>

// Our custom QoS parameters
#define BUFFER_SIZE 1024
#define PACKET_COUNT 100
#define INTERVAL 1000000  // Microseconds

static volatile sig_atomic_t done = 0;

// Signal handler for graceful shutdown
void signal_handler(int signum) {
    done = 1;
}

int main(int argc, char *argv[]) {
    // Validate command-line arguments
    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize variables
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    int sockfd, packet_size, i;
    struct timeval start, end;
    double elapsed_time, avg_latency, total_latency = 0.0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Get the host information
    host_info = gethostbyname(argv[1]);
    if (host_info == NULL) {
        perror("Error getting host information");
        return EXIT_FAILURE;
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr = *((struct in_addr *)host_info->h_addr);

    // Set up signal handler for graceful shutdown
    signal(SIGINT, signal_handler);

    // Main monitoring loop
    while (!done) {
        // Send a packet
        packet_size = sendto(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (packet_size < 0) {
            perror("Error sending packet");
            continue;
        }

        // Start the timer
        gettimeofday(&start, NULL);

        // Receive the response
        packet_size = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (packet_size < 0) {
            perror("Error receiving response");
            continue;
        }

        // Stop the timer
        gettimeofday(&end, NULL);

        // Calculate the latency
        elapsed_time = ((double)(end.tv_sec - start.tv_sec) * 1000000) + ((double)(end.tv_usec - start.tv_usec));
        total_latency += elapsed_time;

        // Update the statistics
        avg_latency = total_latency / (double)i;

        // Print the results
        printf("Packet %d: Size: %d bytes, Latency: %.2f ms, Average Latency: %.2f ms\n", i, packet_size, elapsed_time / 1000, avg_latency / 1000);
        
        // Sleep for the specified interval
        usleep(INTERVAL);

        // Increment the packet count
        i++;

        // Check if we've reached the packet count limit
        if (i >= PACKET_COUNT) {
            done = 1;
        }
    }

    // Close the socket
    close(sockfd);

    // Print the final statistics
    printf("\nNetwork QoS Monitoring Report:\n");
    printf("Total Packets Sent: %d\n", i);
    printf("Average Latency: %.2f ms\n", avg_latency / 1000);

    return EXIT_SUCCESS;
}