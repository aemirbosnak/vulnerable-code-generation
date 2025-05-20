//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
#define CPU_STAT_PATH "/proc/stat"
#define SLEEP_INTERVAL 1

// Function to read the CPU statistics from /proc/stat
void read_cpu_stats(long long *user, long long *nice, long long *system, long long *idle) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    
    fp = fopen(CPU_STAT_PATH, "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line of /proc/stat
    fgets(buffer, BUFFER_SIZE, fp);
    sscanf(buffer, "cpu %lld %lld %lld %lld", user, nice, system, idle);

    fclose(fp);
}

// Function to calculate CPU usage
double calculate_cpu_usage(long long user, long long nice, long long system, long long idle, 
                           long long prev_user, long long prev_nice, long long prev_system, long long prev_idle) {
    long long total_cpu_time = (user + nice + system + idle);
    long long prev_total_cpu_time = (prev_user + prev_nice + prev_system + prev_idle);
    
    long long total_time_diff = total_cpu_time - prev_total_cpu_time;
    long long idle_time_diff = idle - prev_idle;

    // CPU usage calculation
    return 100.0 * (total_time_diff - idle_time_diff) / total_time_diff;
}

int main() {
    long long user, nice, system, idle;
    long long prev_user, prev_nice, prev_system, prev_idle;
    double cpu_usage;
    
    // Initial read
    read_cpu_stats(&prev_user, &prev_nice, &prev_system, &prev_idle);

    while (1) {
        // Sleep for specified interval
        sleep(SLEEP_INTERVAL);
        
        // Read current CPU stats
        read_cpu_stats(&user, &nice, &system, &idle);

        // Calculate CPU usage
        cpu_usage = calculate_cpu_usage(user, nice, system, idle, 
                                        prev_user, prev_nice, prev_system, prev_idle);
        
        // Print CPU usage
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        
        // Update previous values for next iteration
        prev_user = user;
        prev_nice = nice;
        prev_system = system;
        prev_idle = idle;
    }

    return 0;
}