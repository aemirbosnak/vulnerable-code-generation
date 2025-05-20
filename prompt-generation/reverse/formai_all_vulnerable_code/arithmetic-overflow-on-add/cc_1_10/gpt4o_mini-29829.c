//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CPU_INFO_FILE "/proc/stat"

// Function to read the CPU statistics from /proc/stat
void read_cpu_stats(long long *user, long long *nice, long long *system, long long *idle) {
    FILE *file = fopen(CPU_INFO_FILE, "r");
    if (!file) {
        perror("Unable to open CPU stats file");
        exit(EXIT_FAILURE);
    }
    
    char buffer[256];
    fgets(buffer, sizeof(buffer), file); // Read the first line
    sscanf(buffer, "cpu %lld %lld %lld %lld", user, nice, system, idle);
    
    fclose(file);
}

// Function to calculate CPU usage percentage
double calculate_cpu_usage(long long prev_idle, long long prev_total, long long idle, long long total) {
    long long total_diff = total - prev_total;
    long long idle_diff = idle - prev_idle;

    if (total_diff == 0) return 0.0; // Avoid division by zero

    double usage = 100.0 * (1.0 - (double)idle_diff / (double)total_diff);
    return usage;
}

int main() {
    long long prev_user, prev_nice, prev_system, prev_idle;
    long long user, nice, system, idle;

    // Initialize previous statistics
    read_cpu_stats(&prev_user, &prev_nice, &prev_system, &prev_idle);
    long long prev_total = prev_user + prev_nice + prev_system + prev_idle;

    while (1) {
        sleep(1); // Wait for 1 second

        read_cpu_stats(&user, &nice, &system, &idle);
        long long total = user + nice + system + idle;

        // Calculate CPU usage
        double cpu_usage = calculate_cpu_usage(prev_idle, prev_total, idle, total);

        // Print the CPU usage
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        // Update previous statistics
        prev_user = user;
        prev_nice = nice;
        prev_system = system;
        prev_idle = idle;
        prev_total = total;
    }

    return 0;
}