//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_CPUS 16

typedef struct {
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
    unsigned long steal;
} cpu_stats_t;

void read_cpu_stats(cpu_stats_t *stats) {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
           &stats->user,
           &stats->nice,
           &stats->system,
           &stats->idle,
           &stats->iowait,
           &stats->irq,
           &stats->softirq,
           &stats->steal);

    fclose(file);
}

void calculate_cpu_usage(cpu_stats_t *previous, cpu_stats_t *current, double *usage) {
    unsigned long prev_total = previous->user + previous->nice + previous->system + previous->idle + previous->iowait +
                                previous->irq + previous->softirq + previous->steal;

    unsigned long curr_total = current->user + current->nice + current->system + current->idle + current->iowait +
                                current->irq + current->softirq + current->steal;

    unsigned long prev_idle = previous->idle + previous->iowait;
    unsigned long curr_idle = current->idle + current->iowait;

    unsigned long total_diff = curr_total - prev_total;
    unsigned long idle_diff = curr_idle - prev_idle;

    if (total_diff > 0) {
        *usage = (1.0 - (double)idle_diff / total_diff) * 100.0;
    } else {
        *usage = 0.0;
    }
}

int main() {
    cpu_stats_t previous_stats;
    cpu_stats_t current_stats;
    double cpu_usage;

    // Initial read
    read_cpu_stats(&previous_stats);

    while (1) {
        // Sleep for 1 second
        sleep(1);

        // Read current CPU stats
        read_cpu_stats(&current_stats);

        // Calculate CPU usage
        calculate_cpu_usage(&previous_stats, &current_stats, &cpu_usage);

        // Print the CPU usage
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        // Update previous stats
        previous_stats = current_stats;
    }

    return 0;
}