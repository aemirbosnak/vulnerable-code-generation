//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PINGS 10
#define TARGET_HOST "8.8.8.8"  // Google Public DNS for testing

void ping_host(const char *host);
long calculate_average(long times[], int count);
void print_statistics(long times[], int count, int lost_packets);

int main() {
    long response_times[MAX_PINGS];
    int lost_packets = 0;
    int ping_count = 0;

    printf("Starting QoS Monitor...\n");
    printf("Pinging %s for %d pings...\n", TARGET_HOST, MAX_PINGS);
    
    while (ping_count < MAX_PINGS) {
        ping_host(TARGET_HOST);
        // Simulating response time for the sake of this example
        struct timeval start, end;
        gettimeofday(&start, NULL);
        
        // Simulating time taken for a round trip to the host
        usleep(rand() % 500000 + 100000); // Simulate a RTT between 0.1s to 0.6s
        
        gettimeofday(&end, NULL);
        long response_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
        
        if (response_time < 500000) {
            response_times[ping_count] = response_time;
            printf("Reply from %s: time=%.3f ms\n", TARGET_HOST, response_time / 1000.0);
        } else {
            lost_packets++;
            printf("Request timed out.\n");
        }

        ping_count++;
        sleep(1); // Wait before the next ping
    }

    print_statistics(response_times, ping_count, lost_packets);
    return 0;
}

void ping_host(const char *host) {
    // This function simulates pinging a host, so we do not implement actual networking here.
}

long calculate_average(long times[], int count) {
    long sum = 0;
    for (int i = 0; i < count; i++) {
        sum += times[i];
    }
    return (count > 0) ? (sum / count) : 0;
}

void print_statistics(long times[], int count, int lost_packets) {
    printf("\n--- QoS Statistics ---\n");
    printf("Total Pings Sent: %d\n", count);
    printf("Total Lost Packets: %d\n", lost_packets);
    
    // Non-lost responses
    int successful_pings = count - lost_packets;

    if (successful_pings > 0) {
        long average_time = calculate_average(times, successful_pings);
        printf("Average response time: %.3f ms\n", average_time / 1000.0);
    } else {
        printf("No successful pings to calculate an average.\n");
    }
    
    printf("----------------------\n");
}