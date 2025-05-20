//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 256

typedef struct {
    long user;
    long nice;
    long system;
    long idle;
    long iowait;
    long irq;
    long softirq;
    long steal;
    long guest;
    long guest_nice;
} CpuStat;

void read_cpu_stat(CpuStat *cpu_stat) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    char buffer[BUFFER_SIZE];
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
           &cpu_stat->user, &cpu_stat->nice, &cpu_stat->system,
           &cpu_stat->idle, &cpu_stat->iowait, &cpu_stat->irq,
           &cpu_stat->softirq, &cpu_stat->steal,
           &cpu_stat->guest, &cpu_stat->guest_nice);
    
    fclose(fp);
}

long calculate_cpu_usage(CpuStat *prev, CpuStat *curr) {
    long prev_idle = prev->idle + prev->iowait;
    long curr_idle = curr->idle + curr->iowait;

    long prev_total = prev->user + prev->nice + prev->system + prev_idle +
                      prev->irq + prev->softirq + prev->steal;
    long curr_total = curr->user + curr->nice + curr->system + curr_idle +
                      curr->irq + curr->softirq + curr->steal;

    long total_diff = curr_total - prev_total;
    long idle_diff = curr_idle - prev_idle;

    return (total_diff - idle_diff) * 100 / total_diff;
}

void display_cpu_usage() {
    CpuStat prev_stat, curr_stat;

    // Initial read to get the first CPU statistics
    read_cpu_stat(&prev_stat);
    sleep(1); // Wait for a second
    
    while (true) {
        // Read current CPU statistics
        read_cpu_stat(&curr_stat);
        
        // Calculate CPU usage
        long cpu_usage = calculate_cpu_usage(&prev_stat, &curr_stat);
        
        // Display CPU usage
        printf("\rCPU Usage: %ld%%", cpu_usage);
        fflush(stdout);
        
        // Update previous stats
        prev_stat = curr_stat;

        // Wait for a second before the next read
        sleep(1);
    }
}

int main() {
    printf("CPU Usage Monitor\n");
    printf("Press Ctrl+C to stop the monitor.\n");
    
    display_cpu_usage();

    return 0;
}