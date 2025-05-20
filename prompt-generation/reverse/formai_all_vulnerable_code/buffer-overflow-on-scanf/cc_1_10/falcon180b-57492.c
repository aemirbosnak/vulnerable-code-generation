//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKETS 100
#define MAX_DELAY 100 // in milliseconds

typedef struct {
    int delay;
    int packet_size;
} Packet;

int main() {
    int num_packets, i;
    Packet packets[MAX_PACKETS];

    // Read number of packets
    printf("Enter the number of packets: ");
    scanf("%d", &num_packets);

    // Read packet details
    for (i = 0; i < num_packets; i++) {
        printf("Enter delay (in milliseconds) for packet %d: ", i+1);
        scanf("%d", &packets[i].delay);
        printf("Enter packet size for packet %d: ", i+1);
        scanf("%d", &packets[i].packet_size);
    }

    // Simulate network and calculate QoS metrics
    int total_delay = 0;
    int total_packet_size = 0;
    int max_delay = 0;
    int min_delay = MAX_DELAY;
    for (i = 0; i < num_packets; i++) {
        total_delay += packets[i].delay;
        total_packet_size += packets[i].packet_size;

        if (packets[i].delay > max_delay) {
            max_delay = packets[i].delay;
        }

        if (packets[i].delay < min_delay) {
            min_delay = packets[i].delay;
        }
    }

    double avg_delay = (double) total_delay / num_packets;
    double throughput = (double) total_packet_size / total_delay;

    // Print QoS metrics
    printf("Average delay: %.2f ms\n", avg_delay);
    printf("Throughput: %.2f packets/ms\n", throughput);
    printf("Maximum delay: %d ms\n", max_delay);
    printf("Minimum delay: %d ms\n", min_delay);

    return 0;
}