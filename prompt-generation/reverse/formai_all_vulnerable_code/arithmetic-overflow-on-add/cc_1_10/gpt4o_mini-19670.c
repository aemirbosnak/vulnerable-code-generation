//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define PACKETS_TO_SEND 5
#define TARGET_HOST "8.8.8.8"  // You can change this to any reachable host

// Function to get the current time in milliseconds
long get_current_time_ms() {
    struct timeval time_now;
    gettimeofday(&time_now, NULL);
    return (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
}

// Function to simulate sending and receiving packets
void simulate_packet_loss(long *latencies, int *loss_count) {
    for (int i = 0; i < PACKETS_TO_SEND; ++i) {
        long start_time = get_current_time_ms();
        
        // Simulate packet sending
        bool packet_sent = rand() % 10 > 2; // Simulate 20% packet loss
        if (packet_sent) {
            // simulating the delay
            long delay = (rand() % 100) + 1; // simulate some ping time
            usleep(delay * 1000); // sleep for the delay in milliseconds
            latencies[i] = get_current_time_ms() - start_time; // calculate latency
        } else {
            latencies[i] = -1; // -1 indicates packet loss
            (*loss_count)++;
        }
    }
}

// Function to calculate jitter
double calculate_jitter(long *latencies, int count) {
    double jitter = 0.0;
    for (int i = 1; i < count; ++i) {
        if (latencies[i] != -1 && latencies[i - 1] != -1) {
            double diff = (double)(latencies[i] - latencies[i - 1]);
            jitter += (diff < 0) ? -diff : diff; // absolute difference
        }
    }
    return jitter / (count - 1);
}

// Function to display the report
void display_report(long *latencies, int lost_count) {
    int successful_count = PACKETS_TO_SEND - lost_count;
    printf("======= QoS Report =======\n");
    printf("Total Packets Sent: %d\n", PACKETS_TO_SEND);
    printf("Total Packets Lost: %d\n", lost_count);
    printf("Successful Packets: %d\n", successful_count);
    
    double avg_latency = 0;
    int valid_latencies = 0;
    
    for (int i = 0; i < PACKETS_TO_SEND; ++i) {
        if (latencies[i] != -1) {
            avg_latency += latencies[i];
            valid_latencies++;
        }
    }
    
    avg_latency = (valid_latencies == 0) ? 0 : avg_latency / valid_latencies;

    printf("Average Latency: %.2f ms\n", avg_latency);
    printf("Jitter: %.2f ms\n", calculate_jitter(latencies, PACKETS_TO_SEND));
    printf("==========================\n");
}

int main() {
    srand((unsigned int)time(NULL));
    
    long latencies[PACKETS_TO_SEND];
    int loss_count = 0;

    printf("Starting QoS Monitor...\n");
    printf("Monitoring latency, packet loss, and jitter for host: %s\n", TARGET_HOST);

    // Simulate packet monitoring
    simulate_packet_loss(latencies, &loss_count);

    // Display the report
    display_report(latencies, loss_count);

    return 0;
}