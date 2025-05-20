//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Function to read the CPU statistics from /proc/stat
void read_cpu_stats(unsigned long long *user, unsigned long long *nice, 
                    unsigned long long *system, unsigned long long *idle) {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fscanf(file, "%s %llu %llu %llu %llu", buffer, user, nice, system, idle);
    
    fclose(file);
}

// Function to calculate CPU usage
float calculate_cpu_usage(unsigned long long prev_user, unsigned long long prev_nice,
                          unsigned long long prev_system, unsigned long long prev_idle,
                          unsigned long long curr_user, unsigned long long curr_nice,
                          unsigned long long curr_system, unsigned long long curr_idle) {
    unsigned long long total_prev = prev_user + prev_nice + prev_system + prev_idle;
    unsigned long long total_curr = curr_user + curr_nice + curr_system + curr_idle;

    unsigned long long total_busy = (curr_user + curr_nice + curr_system) - 
                                    (prev_user + prev_nice + prev_system);

    return ((float)total_busy / (total_curr - total_prev)) * 100.0f;
}

// Function to monitor CPU usage in a loop
void monitor_cpu_usage() {
    unsigned long long prev_user, prev_nice, prev_system, prev_idle;
    unsigned long long curr_user, curr_nice, curr_system, curr_idle;

    // Initial read of CPU stats
    read_cpu_stats(&prev_user, &prev_nice, &prev_system, &prev_idle);

    while (1) {
        // Sleep for a while before reading stats again
        sleep(1);

        // Read current CPU stats
        read_cpu_stats(&curr_user, &curr_nice, &curr_system, &curr_idle);
    
        // Calculate CPU usage
        float cpu_usage = calculate_cpu_usage(prev_user, prev_nice, prev_system, prev_idle,
                                               curr_user, curr_nice, curr_system, curr_idle);
        
        // Print CPU usage
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        
        // Prepare for next iteration
        prev_user = curr_user;
        prev_nice = curr_nice;
        prev_system = curr_system;
        prev_idle = curr_idle;
    }
}

int main() {
    printf("Welcome to the CPU Usage Monitor!\n");
    printf("Press Ctrl+C to exit.\n\n");
    
    monitor_cpu_usage();
    
    return 0;
}