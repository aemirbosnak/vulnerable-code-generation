//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CPU_COUNT 4 // Number of CPUs to monitor

void get_cpu_times(unsigned long long *cpu_times) {
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read CPU times
    char line[256];
    if (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu",
               &cpu_times[0], &cpu_times[1], &cpu_times[2], &cpu_times[3],
               &cpu_times[4], &cpu_times[5], &cpu_times[6], &cpu_times[7]);
    }

    fclose(file);
}

void calculate_cpu_usage(unsigned long long *prev_cpu_times, unsigned long long *curr_cpu_times, double *cpu_usage) {
    unsigned long long prev_idle = prev_cpu_times[3];
    unsigned long long curr_idle = curr_cpu_times[3];

    unsigned long long prev_total = 0;
    unsigned long long curr_total = 0;

    for (int i = 0; i < 8; i++) {
        prev_total += prev_cpu_times[i];
        curr_total += curr_cpu_times[i];
    }

    unsigned long long idle_duration = curr_idle - prev_idle;
    unsigned long long total_duration = curr_total - prev_total;
    
    // Calculate CPU usage
    if (total_duration > 0) {
        *cpu_usage = ((total_duration - idle_duration) / (double)total_duration) * 100.0;
    } else {
        *cpu_usage = 0.0;
    }
}

void display_cpu_usage(double cpu_usage) {
    printf("CPU Usage: %.2f%%\n", cpu_usage);
}

int main() {
    unsigned long long prev_cpu_times[8] = {0};
    unsigned long long curr_cpu_times[8] = {0};
    double cpu_usage = 0.0;
    
    printf("Starting CPU usage monitor. Press Ctrl+C to exit.\n");
    
    while (1) {
        // Get the previous CPU times
        get_cpu_times(prev_cpu_times);
        
        // Wait for a second before the next read
        sleep(1);

        // Get the current CPU times
        get_cpu_times(curr_cpu_times);
        
        // Calculate CPU usage
        calculate_cpu_usage(prev_cpu_times, curr_cpu_times, &cpu_usage);
        
        // Display CPU usage
        display_cpu_usage(cpu_usage);
    }

    return 0;
}