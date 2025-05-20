//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Data structures
typedef struct {
    long long total;
    long long idle;
} cpu_usage_t;

// Function declarations
cpu_usage_t get_cpu_usage();
void print_cpu_usage(cpu_usage_t usage);

// Main function
int main() {
    // Get the initial CPU usage
    cpu_usage_t usage = get_cpu_usage();

    // Print the initial CPU usage
    print_cpu_usage(usage);

    // Loop forever, getting the CPU usage every second
    while (1) {
        // Get the CPU usage
        cpu_usage_t new_usage = get_cpu_usage();

        // Calculate the difference in CPU usage
        long long usage_diff = new_usage.total - usage.total;
        long long idle_diff = new_usage.idle - usage.idle;

        // Calculate the CPU usage percentage
        double usage_percent = 100.0 * (usage_diff - idle_diff) / usage_diff;

        // Print the CPU usage percentage
        printf("CPU Usage: %.2f%%\n", usage_percent);

        // Update the CPU usage
        usage = new_usage;

        // Sleep for one second
        sleep(1);
    }

    return 0;
}

// Function to get the CPU usage
cpu_usage_t get_cpu_usage() {
    // Open the /proc/stat file
    FILE *f = fopen("/proc/stat", "r");
    if (f == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Read the first line of the file
    char line[1024];
    if (fgets(line, sizeof(line), f) == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }

    // Close the file
    fclose(f);

    // Parse the line into the CPU usage data
    cpu_usage_t usage;
    sscanf(line, "cpu  %lld %lld %lld %lld %lld %lld %lld %lld",
        &usage.total, &usage.idle, &usage.total, &usage.idle, &usage.total, &usage.idle, &usage.total, &usage.idle);

    // Return the CPU usage
    return usage;
}

// Function to print the CPU usage
void print_cpu_usage(cpu_usage_t usage) {
    // Print the CPU usage in a statistical style
    printf("CPU Usage:\n");
    printf("    Total: %lld\n", usage.total);
    printf("    Idle: %lld\n", usage.idle);
    printf("    Usage: %.2f%%\n", 100.0 * (usage.total - usage.idle) / usage.total);
}