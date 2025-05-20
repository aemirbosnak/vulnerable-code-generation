//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256
#define INTERVAL 1

// Function to read CPU statistics from /proc/stat
void read_cpu_stats(long *user, long *nice, long *system, long *idle, long *iowait, long *irq, long *softirq) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld", user, nice, system, idle, iowait, irq, softirq);
    }

    fclose(fp);
}

// Function to calculate CPU usage
double calculate_cpu_usage(long prev_total, long prev_idle, long total, long idle) {
    long total_diff = total - prev_total;
    long idle_diff = idle - prev_idle;
    return (total_diff - idle_diff) * 100.0 / total_diff; // return usage percentage
}

// Main function
int main() {
    long user, nice, system, idle, iowait, irq, softirq;
    long prev_user, prev_nice, prev_system, prev_idle, prev_iowait, prev_irq, prev_softirq;

    // Initial read of CPU stats
    read_cpu_stats(&prev_user, &prev_nice, &prev_system, &prev_idle, &prev_iowait, &prev_irq, &prev_softirq);
    long prev_total = prev_user + prev_nice + prev_system + prev_idle + prev_iowait + prev_irq + prev_softirq;

    while (1) {
        sleep(INTERVAL); // wait for specified interval

        // Read current CPU stats
        read_cpu_stats(&user, &nice, &system, &idle, &iowait, &irq, &softirq);
        long total = user + nice + system + idle + iowait + irq + softirq;

        // Calculate CPU usage
        double cpu_usage = calculate_cpu_usage(prev_total, prev_idle, total, idle);

        // Print CPU usage
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        // Update previous stats
        prev_user = user;
        prev_nice = nice;
        prev_system = system;
        prev_idle = idle;
        prev_iowait = iowait;
        prev_irq = irq;
        prev_softirq = softirq;
        prev_total = total;
    }

    return 0;
}