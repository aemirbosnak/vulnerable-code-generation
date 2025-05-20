//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE 5

typedef struct {
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
} CPUStats;

void get_cpu_stats(CPUStats *cpu_stats) {
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), file); // Read first line

    sscanf(buffer, "cpu %lu %lu %lu %lu %lu", 
           &cpu_stats->user, 
           &cpu_stats->nice, 
           &cpu_stats->system, 
           &cpu_stats->idle, 
           &cpu_stats->iowait);

    fclose(file);
}

void calculate_cpu_usage(CPUStats *prev_stats, CPUStats *curr_stats, double *usage) {
    unsigned long prev_idle = prev_stats->idle + prev_stats->iowait;
    unsigned long curr_idle = curr_stats->idle + curr_stats->iowait;

    unsigned long prev_total = prev_stats->user + prev_stats->nice + 
                                prev_stats->system + prev_idle;
    unsigned long curr_total = curr_stats->user + curr_stats->nice + 
                                curr_stats->system + curr_idle;

    unsigned long total_diff = curr_total - prev_total;
    unsigned long idle_diff = curr_idle - prev_idle;

    if (total_diff == 0) {
        *usage = 0.0;
    } else {
        *usage = (total_diff - idle_diff) / (double)total_diff * 100.0;
    }
}

void print_usage(double usage) {
    time_t now;
    time(&now);
    char timestamp[100];
    struct tm *tm_info = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);

    printf("%s - CPU Usage: %.2f%%\n", timestamp, usage);
}

int main() {
    CPUStats prev_stats, curr_stats;
    double cpu_usage;

    // Initial reading
    get_cpu_stats(&prev_stats);
    sleep(1); // Sleep for one second to measure over a period of time

    while (1) {
        get_cpu_stats(&curr_stats);
        calculate_cpu_usage(&prev_stats, &curr_stats, &cpu_usage);
        print_usage(cpu_usage);
        
        // Prepare for next iteration
        prev_stats = curr_stats;
        sleep(1); // Sleep for one more second before the next measurement
    }

    return 0;
}