//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PROC_STAT_PATH "/proc/stat"
#define BUFFER_SIZE 256

void read_cpu_usage(int *user, int *nice, int *system, int *idle, int *iowait, int *irq, int *softirq) {
    FILE *fp = fopen(PROC_STAT_PATH, "r");
    if (fp == NULL) {
        printf("Could not open %s for reading\n", PROC_STAT_PATH);
        return;
    }

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, fp); // Read the first line which contains the CPU stats

    sscanf(buffer, "cpu %d %d %d %d %d %d %d", user, nice, system, idle, iowait, irq, softirq);
    
    fclose(fp);
}

void calculate_cpu_percentage(int *cpu_stats_prev, int *cpu_stats_curr, double *cpu_usage) {
    int total_prev = 0, total_curr = 0;
    
    for (int i = 0; i < 7; i++) {
        total_prev += cpu_stats_prev[i];
        total_curr += cpu_stats_curr[i];
    }

    int total_diff = total_curr - total_prev;
    int idle_diff = cpu_stats_curr[3] - cpu_stats_prev[3]; // Idle time

    if (total_diff > 0) {
        *cpu_usage = 100.0 * (total_diff - idle_diff) / total_diff;
    } else {
        *cpu_usage = 0.0;
    }
}

void display_cpu_usage(double cpu_usage) {
    printf("\rCPU Usage: %.2f%%", cpu_usage);
    fflush(stdout);
}

int main() {
    int cpu_stats_prev[7] = {0};
    int cpu_stats_curr[7] = {0};
    double cpu_usage = 0.0;

    read_cpu_usage(&cpu_stats_prev[0], &cpu_stats_prev[1], &cpu_stats_prev[2], &cpu_stats_prev[3], 
                   &cpu_stats_prev[4], &cpu_stats_prev[5], &cpu_stats_prev[6]);

    while (1) {
        sleep(1); // Gather CPU usage every 1 second
        read_cpu_usage(&cpu_stats_curr[0], &cpu_stats_curr[1], &cpu_stats_curr[2], &cpu_stats_curr[3], 
                       &cpu_stats_curr[4], &cpu_stats_curr[5], &cpu_stats_curr[6]);

        calculate_cpu_percentage(cpu_stats_prev, cpu_stats_curr, &cpu_usage);

        display_cpu_usage(cpu_usage);
        
        // Update previous stats for next iteration
        memcpy(cpu_stats_prev, cpu_stats_curr, sizeof(cpu_stats_prev));
    }

    return 0;
}