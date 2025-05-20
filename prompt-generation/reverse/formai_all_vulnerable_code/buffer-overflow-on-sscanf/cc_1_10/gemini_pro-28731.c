//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#define NUM_SAMPLES 100

typedef struct {
    time_t time;
    double cpu_usage;
} sample_t;

int main() {
    sample_t samples[NUM_SAMPLES];

    // Get initial time
    time(&samples[0].time);
    samples[0].cpu_usage = 0.0;

    // Get CPU usage samples
    for (int i = 1; i < NUM_SAMPLES; i++) {
        // Get current time
        time(&samples[i].time);

        // Get CPU usage
        FILE *fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            perror("fopen");
            return 1;
        }

        char line[1024];
        while (fgets(line, sizeof(line), fp) != NULL) {
            if (strncmp(line, "cpu ", 4) == 0) {
                char *ptr = line;

                // Skip "cpu "
                ptr += 4;

                // Parse CPU usage
                int user, nice, system, idle, iowait, irq, softirq;
                ptr = sscanf(ptr, "%d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);
                if (ptr == 7) {
                    double total = user + nice + system + idle + iowait + irq + softirq;
                    double idle_percent = idle / total;
                    samples[i].cpu_usage = 100.0 - idle_percent;
                }
                break;
            }
        }

        fclose(fp);
    }

    // Calculate statistics
    double min_cpu = samples[0].cpu_usage;
    double max_cpu = samples[0].cpu_usage;
    double avg_cpu = samples[0].cpu_usage;
    for (int i = 1; i < NUM_SAMPLES; i++) {
        if (samples[i].cpu_usage < min_cpu) {
            min_cpu = samples[i].cpu_usage;
        }
        if (samples[i].cpu_usage > max_cpu) {
            max_cpu = samples[i].cpu_usage;
        }
        avg_cpu += samples[i].cpu_usage;
    }
    avg_cpu /= NUM_SAMPLES;

    // Print statistics
    printf("CPU usage statistics:\n");
    printf("  Minimum: %.2f%%\n", min_cpu);
    printf("  Maximum: %.2f%%\n", max_cpu);
    printf("  Average: %.2f%%\n", avg_cpu);

    return 0;
}