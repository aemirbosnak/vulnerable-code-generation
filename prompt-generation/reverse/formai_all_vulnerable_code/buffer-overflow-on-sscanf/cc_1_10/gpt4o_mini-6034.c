//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TOTAL_FIELDS 10
#define STAT_FIELDS 4

// Function to read CPU statistics from /proc/stat
void read_cpu_stats(unsigned long long *cpu_times) {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    fclose(file);

    sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", 
           &cpu_times[0], &cpu_times[1], &cpu_times[2], 
           &cpu_times[3], &cpu_times[4], &cpu_times[5], 
           &cpu_times[6], &cpu_times[7], &cpu_times[8], 
           &cpu_times[9]);
}

// Function to calculate CPU usage percentage
double calculate_cpu_usage(unsigned long long *prev, unsigned long long *curr) {
    unsigned long long prev_idle = prev[3] + prev[4];
    unsigned long long curr_idle = curr[3] + curr[4];

    unsigned long long total_prev = 0;
    unsigned long long total_curr = 0;

    for (int i = 0; i < TOTAL_FIELDS; i++) {
        total_prev += prev[i];
        total_curr += curr[i];
    }

    unsigned long long total_diff = total_curr - total_prev;
    unsigned long long idle_diff = curr_idle - prev_idle;

    return (double)(total_diff - idle_diff) / total_diff * 100.0;
}

// Main function for monitoring CPU usage
int main() {
    unsigned long long prev_cpu_times[TOTAL_FIELDS] = {0};
    unsigned long long curr_cpu_times[TOTAL_FIELDS] = {0};

    // Read initial CPU stats.
    read_cpu_stats(prev_cpu_times);

    printf("Monitoring CPU usage. Press Ctrl+C to exit...\n");

    while (1) {
        sleep(1); // Wait for one second.
        
        // Read the current CPU stats.
        read_cpu_stats(curr_cpu_times);
        
        // Calculate the CPU usage percentage.
        double cpu_usage = calculate_cpu_usage(prev_cpu_times, curr_cpu_times);
        
        // Display the CPU usage.
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        
        // Update previous CPU times for the next iteration.
        memcpy(prev_cpu_times, curr_cpu_times, sizeof(prev_cpu_times));
    }

    return 0;
}