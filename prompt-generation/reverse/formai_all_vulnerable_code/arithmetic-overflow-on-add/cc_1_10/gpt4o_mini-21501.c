//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define DELAY 1

void read_cpu_usage(long *user, long *nice, long *system, long *idle) {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);

    sscanf(buffer, "cpu %ld %ld %ld %ld", user, nice, system, idle);
    fclose(fp);
}

double calculate_cpu_usage(long prev_user, long prev_nice, long prev_system, long prev_idle,
                            long curr_user, long curr_nice, long curr_system, long curr_idle) {
    long total_prev = prev_user + prev_nice + prev_system + prev_idle;
    long total_curr = curr_user + curr_nice + curr_system + curr_idle;

    long total_diff = total_curr - total_prev;
    long idle_diff = curr_idle - prev_idle;

    // Avoid division by zero and calculate CPU usage percentage
    if (total_diff == 0) return 0.0;

    return ((total_diff - idle_diff) * 100.0) / total_diff;
}

int main() {
    long user, nice, system, idle;
    long prev_user, prev_nice, prev_system, prev_idle;

    // Initial read
    read_cpu_usage(&prev_user, &prev_nice, &prev_system, &prev_idle);
    
    printf("Monitoring CPU usage. Press Ctrl+C to stop.\n");

    while (1) {
        sleep(DELAY);

        // Read current CPU usage
        read_cpu_usage(&user, &nice, &system, &idle);

        // Calculate CPU usage
        double cpu_usage = calculate_cpu_usage(prev_user, prev_nice, prev_system, prev_idle,
                                               user, nice, system, idle);

        // Print the result
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        // Update previous values for the next iteration
        prev_user = user;
        prev_nice = nice;
        prev_system = system;
        prev_idle = idle;
    }

    return 0;
}