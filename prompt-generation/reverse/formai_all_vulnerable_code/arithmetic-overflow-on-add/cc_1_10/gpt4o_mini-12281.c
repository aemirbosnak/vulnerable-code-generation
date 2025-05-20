//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
#define CPU_USAGE_FILE "/proc/stat"

// Function to read CPU stats from /proc/stat
void read_cpu_stats(long long *user, long long *nice, long long *system, long long *idle, long long *iowait, long long *irq, long long *softirq, long long *steal) {
    FILE *fp = fopen(CPU_USAGE_FILE, "r");
    if (fp == NULL) {
        perror("Failed to open cpu stats");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];

    // Read the first line of /proc/stat
    if (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        sscanf(buffer, "cpu %lld %lld %lld %lld %lld %lld %lld %lld",
               user, nice, system, idle, iowait, irq, softirq, steal);
    } else {
        perror("Failed to read cpu stats");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
}

// Function to calculate CPU usage percentage
double calculate_cpu_usage(long long prev_user, long long prev_nice, long long prev_system,
                            long long prev_idle, long long prev_iowait, long long prev_irq,
                            long long prev_softirq, long long prev_steal,
                            long long curr_user, long long curr_nice, long long curr_system,
                            long long curr_idle, long long curr_iowait, long long curr_irq,
                            long long curr_softirq, long long curr_steal) {
    long long prev_total = prev_user + prev_nice + prev_system + prev_idle + prev_iowait + prev_irq + prev_softirq + prev_steal;
    long long curr_total = curr_user + curr_nice + curr_system + curr_idle + curr_iowait + curr_irq + curr_softirq + curr_steal;

    long long total_diff = curr_total - prev_total;
    long long idle_diff = curr_idle - prev_idle;

    if (total_diff == 0) return 0.0; // Avoid division by zero

    return ((total_diff - idle_diff) * 100.0) / total_diff;
}

// Main function
int main() {
    long long prev_user, prev_nice, prev_system, prev_idle;
    long long prev_iowait, prev_irq, prev_softirq, prev_steal;
    long long curr_user, curr_nice, curr_system, curr_idle;
    long long curr_iowait, curr_irq, curr_softirq, curr_steal;

    // Initial read of CPU stats
    read_cpu_stats(&prev_user, &prev_nice, &prev_system, &prev_idle,
                   &prev_iowait, &prev_irq, &prev_softirq, &prev_steal);

    // Monitor CPU usage in a loop
    while (1) {
        sleep(1); // Sleep for one second

        // Read current CPU stats
        read_cpu_stats(&curr_user, &curr_nice, &curr_system, &curr_idle,
                       &curr_iowait, &curr_irq, &curr_softirq, &curr_steal);

        // Calculate CPU usage
        double cpu_usage = calculate_cpu_usage(prev_user, prev_nice, prev_system,
                                                prev_idle, prev_iowait, prev_irq,
                                                prev_softirq, prev_steal,
                                                curr_user, curr_nice, curr_system,
                                                curr_idle, curr_iowait, curr_irq,
                                                curr_softirq, curr_steal);

        // Print CPU usage
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        // Update previous statistics to current for the next iteration
        prev_user = curr_user;
        prev_nice = curr_nice;
        prev_system = curr_system;
        prev_idle = curr_idle;
        prev_iowait = curr_iowait;
        prev_irq = curr_irq;
        prev_softirq = curr_softirq;
        prev_steal = curr_steal;
    }

    return 0;
}