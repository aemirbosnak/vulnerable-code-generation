//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define NUM_TESTS 5

typedef struct {
    double latency; // in milliseconds
    double jitter; // in milliseconds
    double packet_loss; // in percentage
} QoSStats;

void printHeader() {
    printf("Network Quality of Service (QoS) Monitor\n");
    printf("========================================\n");
    printf("Test # | Latency (ms) | Jitter (ms) | Packet Loss (%)\n");
    printf("=====================================================\n");
}

void simulateNetworkTest(QoSStats *stats, int testNum) {
    srand(time(NULL) + testNum); // Seed randomness based on test number
    stats->latency = (rand() % 100) + 10; // Simulating latency between 10ms and 109ms
    stats->jitter = (double)(rand() % 30); // Simulating jitter between 0ms and 29ms
    stats->packet_loss = (double)(rand() % 100); // Simulating packet loss as a percentage
}

void printStats(QoSStats stats, int testNum) {
    printf("  %2d   |   %.2f       |   %.2f      |   %.2f\n",
            testNum, stats.latency, stats.jitter, stats.packet_loss);
}

void saveResultsToFile(QoSStats *results) {
    FILE *file = fopen("qos_results.txt", "w");
    if (!file) {
        perror("Could not open file to write results");
        return;
    }

    fprintf(file, "Test # | Latency (ms) | Jitter (ms) | Packet Loss (%)\n");
    fprintf(file, "=====================================================\n");
    for (int i = 0; i < NUM_TESTS; i++) {
        fprintf(file, "  %2d   |   %.2f       |   %.2f      |   %.2f\n",
                i + 1, results[i].latency, results[i].jitter, results[i].packet_loss);
    }
    fclose(file);
    printf("Results saved to qos_results.txt\n");
}

void printSummary(QoSStats *results) {
    double totalLatency = 0, totalJitter = 0, totalPacketLoss = 0;

    for (int i = 0; i < NUM_TESTS; i++) {
        totalLatency += results[i].latency;
        totalJitter += results[i].jitter;
        totalPacketLoss += results[i].packet_loss;
    }

    printf("\nSummary Statistics:\n");
    printf("Average Latency: %.2f ms\n", totalLatency / NUM_TESTS);
    printf("Average Jitter: %.2f ms\n", totalJitter / NUM_TESTS);
    printf("Average Packet Loss: %.2f%%\n", totalPacketLoss / NUM_TESTS);
}

int main() {
    QoSStats results[NUM_TESTS];

    printHeader();

    for (int i = 0; i < NUM_TESTS; i++) {
        simulateNetworkTest(&results[i], i + 1);
        printStats(results[i], i + 1);
    }

    printSummary(results);
    saveResultsToFile(results);
    
    return 0;
}