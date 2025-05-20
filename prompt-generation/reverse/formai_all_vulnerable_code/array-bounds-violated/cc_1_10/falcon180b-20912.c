//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SAMPLES 100
#define SAMPLE_INTERVAL_SEC 1

typedef struct {
    time_t timestamp;
    size_t ram_usage;
} RamUsageSample;

int main() {
    RamUsageSample samples[MAX_SAMPLES];
    int sample_count = 0;
    size_t prev_ram_usage = 0;

    while (1) {
        // Get current RAM usage
        size_t ram_usage = 0;
        FILE* fp = fopen("/proc/self/statm", "r");
        if (fp!= NULL) {
            if (fscanf(fp, "%*s %zu", &ram_usage)!= 1) {
                fprintf(stderr, "Error reading RAM usage\n");
            }
            fclose(fp);
        } else {
            fprintf(stderr, "Error opening /proc/self/statm\n");
        }

        // Print current RAM usage
        printf("\rRAM usage: %zu bytes", ram_usage);
        fflush(stdout);

        // Add sample if enough time has passed
        time_t curr_time = time(NULL);
        if (curr_time - samples[sample_count - 1].timestamp >= SAMPLE_INTERVAL_SEC) {
            samples[sample_count].timestamp = curr_time;
            samples[sample_count].ram_usage = ram_usage;
            sample_count = (sample_count + 1) % MAX_SAMPLES;
        }

        // Calculate average RAM usage over samples
        size_t total_ram_usage = 0;
        int sample_count_total = 0;
        for (int i = 0; i < MAX_SAMPLES; i++) {
            if (samples[i].timestamp!= 0) {
                total_ram_usage += samples[i].ram_usage;
                sample_count_total++;
            }
        }
        if (sample_count_total > 0) {
            size_t avg_ram_usage = total_ram_usage / sample_count_total;
            printf("\nAverage RAM usage: %zu bytes\n", avg_ram_usage);
        }

        // Sleep for sample interval
        sleep(SAMPLE_INTERVAL_SEC);
    }

    return 0;
}