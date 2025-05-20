//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 128

typedef struct {
    float user;
    float nice;
    float system;
    float idle;
    float iowait;
    float irq;
    float softirq;
    float steal;
} CPUStats;

void read_cpu_stats(CPUStats *stats) {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Unable to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "cpu %f %f %f %f %f %f %f %f",
               &stats->user, &stats->nice, &stats->system,
               &stats->idle, &stats->iowait, &stats->irq,
               &stats->softirq, &stats->steal);
    }

    fclose(file);
}

float calculate_cpu_usage(CPUStats *prev, CPUStats *curr) {
    float total_prev = prev->user + prev->nice + prev->system +
                       prev->idle + prev->iowait + prev->irq +
                       prev->softirq + prev->steal;

    float total_curr = curr->user + curr->nice + curr->system +
                       curr->idle + curr->iowait + curr->irq +
                       curr->softirq + curr->steal;

    float total_diff = total_curr - total_prev;
    float idle_diff = curr->idle - prev->idle;

    return ((total_diff - idle_diff) / total_diff) * 100.0;
}

void display_cpu_usage(float usage) {
    printf("Current CPU Usage: %.2f%%\n", usage);
}

int main() {
    CPUStats prev_stats, curr_stats;
    read_cpu_stats(&prev_stats);

    while (1) {
        sleep(1);  // Sleep for one second
        read_cpu_stats(&curr_stats);

        float cpu_usage = calculate_cpu_usage(&prev_stats, &curr_stats);
        display_cpu_usage(cpu_usage);

        prev_stats = curr_stats;  // Update previous stats
    }

    return 0;
}