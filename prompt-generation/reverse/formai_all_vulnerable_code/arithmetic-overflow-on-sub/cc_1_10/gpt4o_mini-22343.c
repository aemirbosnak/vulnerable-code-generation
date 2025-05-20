//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/time.h>

#define MAX_PINGS 10
#define SERVER_IP "8.8.8.8" // Google Public DNS for demonstration
#define TIMEOUT 1           // timeout for ping in seconds

void ping(const char *hostname, int pings) {
    struct timeval start, end;
    double total_time = 0.0;
    int successful_pings = 0;
    int packet_loss = pings; // Assume all packets are lost initially

    for (int i = 0; i < pings; i++) {
        gettimeofday(&start, NULL); // Record start time

        // Simulate a ping using system call
        char command[100];
        snprintf(command, sizeof(command), "ping -c 1 -W %d %s > /dev/null", TIMEOUT, hostname);
        
        int result = system(command);

        gettimeofday(&end, NULL); // Record end time

        // Calculate elapsed time
        double elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0; // convert seconds to ms
        elapsed_time += (end.tv_usec - start.tv_usec) / 1000.0;      // convert microseconds to ms

        if (result == 0) { // Ping successful
            successful_pings++;
            total_time += elapsed_time;
            printf("Reply from %s: time=%.2f ms\n", hostname, elapsed_time);
        } else {
            printf("Request timed out for %s.\n", hostname);
        }

        sleep(1); // Wait before next ping
    }

    packet_loss = pings - successful_pings; // Determine packet loss
    printf("\n--- %s Ping Statistics ---\n", hostname);
    printf("%d packets transmitted, %d received, %d%% packet loss\n",
           pings, successful_pings, (packet_loss * 100) / pings);

    if (successful_pings > 0) {
        printf("Average time: %.2f ms\n", total_time / successful_pings);
    }
}

void monitor_jitter(const char *hostname, int pings) {
    struct timeval ping_times[MAX_PINGS];
    int successful_pings = 0;

    // Conduct pings and store successful timings
    for (int i = 0; i < pings; i++) {
        struct timeval start;
        gettimeofday(&start, NULL);

        char command[100];
        snprintf(command, sizeof(command), "ping -c 1 -W %d %s > /dev/null", TIMEOUT, hostname);
        
        int result = system(command);

        if (result == 0) {
            ping_times[successful_pings++] = start;
            sleep(1); // Wait before next ping
        } else {
            printf("Ping failed on attempt %d.\n", i + 1);
        }
    }

    // Calculate jitter if we have successful pings
    if (successful_pings > 1) {
        double jitter_sum = 0.0;

        for (int i = 1; i < successful_pings; i++) {
            double diff = (ping_times[i].tv_sec - ping_times[i - 1].tv_sec) * 1000.0 + 
                          (ping_times[i].tv_usec - ping_times[i - 1].tv_usec) / 1000.0;
            jitter_sum += fabs(diff);
        }

        double jitter = jitter_sum / (successful_pings - 1);
        printf("Calculated Jitter: %.2f ms\n", jitter);
    } else {
        printf("Not enough successful pings to calculate jitter.\n");
    }
}

int main() {
    printf("Starting Network QoS Monitor...\n");
    printf("Monitoring network statistics to %s...\n", SERVER_IP);

    ping(SERVER_IP, MAX_PINGS);
    monitor_jitter(SERVER_IP, MAX_PINGS);

    return 0;
}