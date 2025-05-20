//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

#define ARRAY_SIZE 10

// Function to calculate CPU usage based on idle and total time
double calculate_cpu_usage(unsigned long long idle_time, unsigned long long total_time) {
    static unsigned long long prev_total_time = 0;
    static unsigned long long prev_idle_time = 0;
    
    unsigned long long total_diff = total_time - prev_total_time;
    unsigned long long idle_diff = idle_time - prev_idle_time;
    
    prev_total_time = total_time;
    prev_idle_time = idle_time;

    if (total_diff == 0) return 0.0;

    return (1.0 - ((double)idle_diff / (double)total_diff)) * 100;
}

// Structure to hold CPU statistics
typedef struct {
    unsigned long long user_time;
    unsigned long long nice_time;
    unsigned long long system_time;
    unsigned long long idle_time;
    unsigned long long iowait_time;
    unsigned long long irq_time;
    unsigned long long softirq_time;
    unsigned long long total_time;
} CPUStats;

// Function to read CPU statistics from /proc/stat
CPUStats read_cpu_stats() {
    CPUStats stats;
    FILE* file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to read CPU stats");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "cpu %llu %llu %llu %llu %llu %llu %llu",
           &stats.user_time, &stats.nice_time, &stats.system_time,
           &stats.idle_time, &stats.iowait_time, &stats.irq_time,
           &stats.softirq_time);
    
    stats.total_time = stats.user_time + stats.nice_time + stats.system_time +
                       stats.idle_time + stats.iowait_time + stats.irq_time +
                       stats.softirq_time;

    fclose(file);
    return stats;
}

// Function to monitor CPU usage for a certain number of iterations
void monitor_cpu_usage(int iterations, int delay_seconds) {
    for (int i = 0; i < iterations; i++) {
        CPUStats stats_before = read_cpu_stats();
        sleep(delay_seconds);
        CPUStats stats_after = read_cpu_stats();

        double cpu_usage = calculate_cpu_usage(stats_after.idle_time, stats_after.total_time);
        printf("CPU Usage: %.2f%%\n", cpu_usage);
    }
}

// Main function to initiate the CPU usage monitor
int main(int argc, char* argv[]) {
    int iterations = 10; // default iterations
    int delay_seconds = 1; // default delay

    // Process command-line arguments
    if (argc > 1) {
        iterations = atoi(argv[1]);
        if (iterations <= 0) {
            fprintf(stderr, "Invalid number of iterations. Using default: 10\n");
            iterations = 10;
        }
    }
    
    if (argc > 2) {
        delay_seconds = atoi(argv[2]);
        if (delay_seconds <= 0) {
            fprintf(stderr, "Invalid delay seconds. Using default: 1\n");
            delay_seconds = 1;
        }
    }

    printf("Starting CPU usage monitor...\n");
    printf("Monitoring for %d iterations with a delay of %d seconds...\n", iterations, delay_seconds);
    
    monitor_cpu_usage(iterations, delay_seconds);
    
    printf("Monitoring completed!\n");
    return 0;
}