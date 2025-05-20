//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int packet_count = 0;
    int dropped_packets = 0;
    int total_packets_sent = 0;
    float packet_loss_rate = 0.0;
    float avg_delay = 0.0;
    float avg_jitter = 0.0;
    float total_delay = 0.0;
    float total_jitter = 0.0;
    float packet_throughput = 0.0;
    float bit_throughput = 0.0;

    // Set random seed for reproducibility
    srand(time(NULL));

    // Simulate sending packets for 1 minute
    for (int i = 0; i < 60000; i++) {
        // Generate random delay and jitter
        float delay = rand() % 10 + 1;
        float jitter = rand() % 5;

        // Update total delay and jitter
        total_delay += delay;
        total_jitter += jitter;

        // Check if packet is dropped
        int is_dropped = rand() % 100 < 10;
        if (is_dropped) {
            dropped_packets++;
        } else {
            packet_count++;
            total_packets_sent++;

            // Update throughput
            packet_throughput = (float) total_packets_sent / i * 60;
            bit_throughput = packet_throughput * 128;

            // Update average delay and jitter
            avg_delay = total_delay / packet_count;
            avg_jitter = total_jitter / packet_count;
        }
    }

    // Calculate packet loss rate
    packet_loss_rate = (float) dropped_packets / total_packets_sent * 100;

    // Print results
    printf("Packet throughput: %.2f packets/sec\n", packet_throughput);
    printf("Bit throughput: %.2f bits/sec\n", bit_throughput);
    printf("Packet loss rate: %.2f%%\n", packet_loss_rate);
    printf("Average delay: %.2f ms\n", avg_delay);
    printf("Average jitter: %.2f ms\n", avg_jitter);

    return 0;
}