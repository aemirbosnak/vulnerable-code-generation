//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define BUFFER_SIZE 256
#define SLEEP_INTERVAL 1

// Function to read CPU statistics from /proc/stat
void read_cpu_stats(unsigned long *user, unsigned long *nice, unsigned long *system, unsigned long *idle) {
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        perror("Failed to read CPU stats");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fclose(file);

    // Parse the line: "cpu  user nice system idle ..."
    sscanf(buffer, "cpu %lu %lu %lu %lu", user, nice, system, idle);
}

// Function to calculate the CPU usage percentage
float calculate_cpu_usage(unsigned long user_start, unsigned long nice_start, unsigned long system_start, unsigned long idle_start,
                          unsigned long user_end, unsigned long nice_end, unsigned long system_end, unsigned long idle_end) {
    unsigned long total_start = user_start + nice_start + system_start + idle_start;
    unsigned long total_end = user_end + nice_end + system_end + idle_end;

    unsigned long total_idle_start = idle_start;
    unsigned long total_idle_end = idle_end;

    unsigned long total_active_start = total_start - total_idle_start;
    unsigned long total_active_end = total_end - total_idle_end;

    unsigned long delta_active = total_active_end - total_active_start;
    unsigned long delta_total = total_end - total_start;

    // Calculate CPU usage percentage
    if (delta_total == 0) return 0.0;
    return (float) delta_active / delta_total * 100;
}

// Function to display CPU usage
void display_cpu_usage(float cpu_usage) {
    printf("CPU Usage: %.2f%%\n", cpu_usage);
}

int main() {
    unsigned long user_start, nice_start, system_start, idle_start;
    unsigned long user_end, nice_end, system_end, idle_end;

    while (true) {
        read_cpu_stats(&user_start, &nice_start, &system_start, &idle_start);
        sleep(SLEEP_INTERVAL);
        read_cpu_stats(&user_end, &nice_end, &system_end, &idle_end);

        float cpu_usage = calculate_cpu_usage(user_start, nice_start, system_start, idle_start,
                                               user_end, nice_end, system_end, idle_end);
        display_cpu_usage(cpu_usage);
    }

    return 0;
}