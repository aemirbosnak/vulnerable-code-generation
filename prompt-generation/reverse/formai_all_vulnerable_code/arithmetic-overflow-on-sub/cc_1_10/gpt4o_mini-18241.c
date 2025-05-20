//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define STAT_INTERVAL 5 // in seconds

typedef struct {
    unsigned long totalPackets;
    unsigned long lostPackets;
    unsigned long receivedPackets;
    double latencies[BUFFER_SIZE]; // to store latency measurements
    size_t latencyCount;
} QoSStats;

void calculate_and_print_statistics(QoSStats *stats) {
    if (stats->receivedPackets > 0) {
        double packetLossPercentage = ((double)stats->lostPackets / stats->totalPackets) * 100;
        double averageLatency = 0.0;

        for (size_t i = 0; i < stats->latencyCount; ++i) {
            averageLatency += stats->latencies[i];
        }
        averageLatency /= stats->latencyCount;

        printf("QoS Statistics:\n");
        printf("Total Packets Sent: %lu\n", stats->totalPackets);
        printf("Packets Received: %lu\n", stats->receivedPackets);
        printf("Packets Lost: %lu\n", stats->lostPackets);
        printf("Packet Loss Percentage: %.2f%%\n", packetLossPercentage);
        printf("Average Latency: %.3f ms\n", averageLatency);
    } else {
        printf("No packets received.\n");
    }
}

void initialize_stats(QoSStats *stats) {
    memset(stats, 0, sizeof(QoSStats));
}

void simulate_qos_monitor(QoSStats *stats) {
    static struct sockaddr_in serverAddr;
    socklen_t addrLen = sizeof(serverAddr);
    char buffer[BUFFER_SIZE];
    
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    
    // Simulating sending a fixed number of packets
    for (int i = 0; i < 100; i++) {
        int sendStatus = sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddr, addrLen);
        stats->totalPackets++;
        
        if (sendStatus < 0) {
            stats->lostPackets++;
            printf("Packet %d lost.\n", i + 1);
        } else {
            stats->receivedPackets++; // Assume all sent packets are received for this simulation
            // Simulating latency measurement
            struct timespec start, end;
            clock_gettime(CLOCK_MONOTONIC, &start);
            usleep(1000 * (rand() % 10)); // simulate network latency
            clock_gettime(CLOCK_MONOTONIC, &end);
            double latency = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
            stats->latencies[stats->latencyCount++] = latency;
        }
        sleep(1); // Simulate a time gap between packets
    }
    
    close(sockfd);
}

int main() {
    QoSStats stats;
    initialize_stats(&stats);
    srand(time(NULL));

    while (1) {
        simulate_qos_monitor(&stats);
        calculate_and_print_statistics(&stats);
        stats.lostPackets = 0; // Reset after printing
        stats.receivedPackets = 0; // Reset after printing
        stats.latencyCount = 0; // Reset after printing
        sleep(STAT_INTERVAL);
    }

    return 0;
}