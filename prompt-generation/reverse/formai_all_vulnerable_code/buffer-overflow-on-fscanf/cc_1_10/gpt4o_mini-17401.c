//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// This structure holds the CPU usage information
typedef struct {
    char cpu[5];
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
    unsigned long long guest;
    unsigned long long guest_nice;
} CpuUsage;

// Function to read CPU statistics from /proc/stat
void readCpuUsage(CpuUsage *usage) {
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Could not open /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    // Read the first line for CPU information
    fscanf(file, "%s %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
           usage->cpu, &usage->user, &usage->nice, &usage->system,
           &usage->idle, &usage->iowait, &usage->irq,
           &usage->softirq, &usage->steal, &usage->guest,
           &usage->guest_nice);
    
    fclose(file);
}

// Function to calculate CPU usage percentage
double calculateCpuUsage(CpuUsage *prev, CpuUsage *curr) {
    unsigned long long prev_total = prev->user + prev->nice + prev->system +
                                     prev->idle + prev->iowait + 
                                     prev->irq + prev->softirq +
                                     prev->steal;
    
    unsigned long long curr_total = curr->user + curr->nice + curr->system +
                                     curr->idle + curr->iowait + 
                                     curr->irq + curr->softirq +
                                     curr->steal;

    unsigned long long total_diff = curr_total - prev_total;
    unsigned long long idle_diff = curr->idle - prev->idle;

    // Avoid division by zero
    if (total_diff == 0) {
        return 0.0;
    }

    // Calculate the CPU usage percentage
    return 100.0 * (total_diff - idle_diff) / total_diff;
}

// Function to display CPU usage
void displayCpuUsage(double usage) {
    printf("Current CPU Usage: %.2f%%\n", usage);
}

int main() {
    CpuUsage prev_usage;
    CpuUsage curr_usage;

    // Read the initial CPU usage
    readCpuUsage(&prev_usage);
    
    // Continuously monitor CPU usage
    while (1) {
        // Sleep for 1 second between reads
        sleep(1);

        // Read the CPU usage again
        readCpuUsage(&curr_usage);

        // Calculate the CPU usage percentage
        double cpu_usage = calculateCpuUsage(&prev_usage, &curr_usage);
        displayCpuUsage(cpu_usage);

        // Update previous usage for the next iteration
        prev_usage = curr_usage;
    }

    return 0;
}