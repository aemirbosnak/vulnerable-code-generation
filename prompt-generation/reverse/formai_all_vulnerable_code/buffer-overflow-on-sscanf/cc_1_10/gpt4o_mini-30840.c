//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_cpu_usage(float *user, float *nice, float *system, float *idle) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Unable to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    // Parse the first line of /proc/stat
    sscanf(buffer, "cpu %f %f %f %f", user, nice, system, idle);
}

void calculate_usage(float user_prev, float nice_prev, float system_prev, float idle_prev, 
                     float *cpu_usage) {
    float user, nice, system, idle;

    get_cpu_usage(&user, &nice, &system, &idle);

    float total_prev = user_prev + nice_prev + system_prev + idle_prev;
    float total_current = user + nice + system + idle;

    // Calculate CPU percentage
    float total_diff = total_current - total_prev;
    float idle_diff = idle - idle_prev;

    *cpu_usage = 100.0 * (total_diff - idle_diff) / total_diff;
}

void monitor_cpu_usage_recursive(void) {
    static float user_prev = 0, nice_prev = 0, system_prev = 0, idle_prev = 0;
    float cpu_usage;

    calculate_usage(user_prev, nice_prev, system_prev, idle_prev, &cpu_usage);

    printf("CPU Usage: %.2f%%\n", cpu_usage);

    // Update previous values
    get_cpu_usage(&user_prev, &nice_prev, &system_prev, &idle_prev);

    // Sleep for 1 second before next update
    sleep(1);

    // Recursive call for continuous monitoring
    monitor_cpu_usage_recursive();
}

int main() {
    printf("Starting CPU Usage Monitor...\n");
    monitor_cpu_usage_recursive();
    return 0;
}