//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define MAX_SAMPLES 1000
#define SAMPLE_INTERVAL 1 // seconds

typedef struct {
    time_t timestamp;
    size_t ram_usage;
} RamUsageSample;

int main() {
    RamUsageSample samples[MAX_SAMPLES];
    int sample_count = 0;
    size_t total_ram_usage = 0;

    while (1) {
        // Get current RAM usage
        struct statvfs svfs;
        if (statvfs("/dev/ram0", &svfs) == -1) {
            printf("Error getting RAM usage\n");
            exit(1);
        }
        size_t current_ram_usage = svfs.f_blocks * svfs.f_frsize;

        // Add sample to buffer
        if (sample_count >= MAX_SAMPLES) {
            sample_count = 0;
        }
        samples[sample_count].timestamp = time(NULL);
        samples[sample_count].ram_usage = current_ram_usage;
        sample_count++;

        // Calculate average RAM usage over last SAMPLE_INTERVAL seconds
        if (sample_count == MAX_SAMPLES) {
            sample_count = 0;
        }
        time_t oldest_timestamp = samples[sample_count].timestamp - SAMPLE_INTERVAL;
        int sample_count_in_interval = 0;
        size_t ram_usage_in_interval = 0;
        for (int i = 0; i < MAX_SAMPLES; i++) {
            if (samples[i].timestamp >= oldest_timestamp) {
                ram_usage_in_interval += samples[i].ram_usage;
                sample_count_in_interval++;
            }
        }
        total_ram_usage += ram_usage_in_interval;

        // Print current and average RAM usage
        printf("Current RAM usage: %zu bytes\n", current_ram_usage);
        printf("Average RAM usage over last %d seconds: %zu bytes\n", SAMPLE_INTERVAL, total_ram_usage / SAMPLE_INTERVAL);
        printf("\n");

        // Sleep for SAMPLE_INTERVAL seconds
        sleep(SAMPLE_INTERVAL);
    }

    return 0;
}