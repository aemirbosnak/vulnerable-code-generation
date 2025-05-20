//GEMINI-pro DATASET v1.0 Category: Networking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAX_LINE 1024

// Custom data structure to store statistical data
typedef struct {
    double sum;                // Sum of values
    double sum_sq;            // Sum of squared values
    double min;                // Minimum value
    double max;                // Maximum value
    int count;               // Number of values
} Stats;

// Function to initialize statistical data structure
void init_stats(Stats *stats) {
    stats->sum = 0.0;
    stats->sum_sq = 0.0;
    stats->min = INFINITY;
    stats->max = -INFINITY;
    stats->count = 0;
}

// Function to update statistical data structure
void update_stats(Stats *stats, double value) {
    stats->sum += value;
    stats->sum_sq += value * value;
    if (value < stats->min) stats->min = value;
    if (value > stats->max) stats->max = value;
    stats->count++;
}

// Function to print statistical data structure
void print_stats(Stats *stats) {
    printf("Count: %d\n", stats->count);
    if (stats->count > 0) {
        printf("Mean: %.2f\n", stats->sum / stats->count);
        printf("Standard deviation: %.2f\n", sqrt(stats->sum_sq / stats->count - (stats->sum / stats->count) * (stats->sum / stats->count)));
        printf("Minimum: %.2f\n", stats->min);
        printf("Maximum: %.2f\n", stats->max);
    } else {
        printf("No data available\n");
    }
}

// Main function
int main() {
    // Initialize statistical data structure
    Stats stats;
    init_stats(&stats);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }
    
    // Bind the socket to an address and port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(5000);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error binding socket");
        return EXIT_FAILURE;
    }
    printf("Waiting for data...\n");
    
    // Receive data from client
    char buffer[MAX_LINE];
    while (1) {
        socklen_t addr_len = sizeof(addr);
        int n = recvfrom(sockfd, buffer, MAX_LINE, 0, (struct sockaddr *)&addr, &addr_len);
        if (n < 0) {
            perror("Error receiving data");
            continue;
        }
        
        // Parse data and update statistical data structure
        double value = atof(buffer);
        update_stats(&stats, value);
        
        // Print statistical data structure every 10 values
        if (stats.count % 10 == 0) {
            print_stats(&stats);
        }
    }
    
    // Close the socket
    close(sockfd);
    
    return EXIT_SUCCESS;
}