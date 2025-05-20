//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// Colors for terminal output
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_RED "\033[0;31m"
#define COLOR_RESET "\033[0m"

// Get CPU usage in percentage
float get_cpu_usage() {
    FILE* fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            // Parse the CPU usage line
            unsigned long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
            sscanf(line, "cpu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
                &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

            // Calculate the total CPU time
            unsigned long total_time = user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;

            // Calculate the idle CPU time
            unsigned long idle_time = idle + iowait;

            // Calculate the CPU usage percentage
            float cpu_usage = (float)(total_time - idle_time) / (float)total_time * 100.0;
            fclose(fp);
            return cpu_usage;
        }
    }

    fclose(fp);
    return -1;
}

int main() {
    // Initialize the previous CPU usage
    float previous_cpu_usage = 0.0;

    // Main loop
    while (1) {
        // Get the current CPU usage
        float cpu_usage = get_cpu_usage();

        // Check if the CPU usage has changed significantly
        if (abs(cpu_usage - previous_cpu_usage) > 5.0) {
            // Update the previous CPU usage
            previous_cpu_usage = cpu_usage;

            // Print the CPU usage
            if (cpu_usage < 30.0) {
                printf(COLOR_GREEN "CPU usage: %.1f%%\n" COLOR_RESET, cpu_usage);
            } else if (cpu_usage < 70.0) {
                printf(COLOR_YELLOW "CPU usage: %.1f%%\n" COLOR_RESET, cpu_usage);
            } else {
                printf(COLOR_RED "CPU usage: %.1f%%\n" COLOR_RESET, cpu_usage);
            }
        }

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}