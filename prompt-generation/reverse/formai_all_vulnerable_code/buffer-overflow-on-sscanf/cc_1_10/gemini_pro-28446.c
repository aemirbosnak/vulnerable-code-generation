//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Define the data structure to store CPU usage information
typedef struct {
    long long total_cpu_time;
    long long total_idle_time;
    long long previous_total_cpu_time;
    long long previous_total_idle_time;
} cpu_usage_info_t;

// Get CPU usage information
void get_cpu_usage_info(cpu_usage_info_t *info) {
    // Open the /proc/stat file
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Read the first line of the file
    char line[1024];
    if (fgets(line, sizeof(line), file) == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }

    // Parse the line to extract the CPU usage information
    sscanf(line, "cpu %lld %lld", &info->total_cpu_time, &info->total_idle_time);

    // Close the file
    fclose(file);
}

// Calculate CPU usage percentage
double calculate_cpu_usage(cpu_usage_info_t *info) {
    // Calculate the total CPU time since the last measurement
    long long total_cpu_time_diff = info->total_cpu_time - info->previous_total_cpu_time;

    // Calculate the total idle time since the last measurement
    long long total_idle_time_diff = info->total_idle_time - info->previous_total_idle_time;

    // Calculate the CPU usage percentage
    double cpu_usage = 100.0 * (total_cpu_time_diff - total_idle_time_diff) / total_cpu_time_diff;

    // Update the previous CPU usage information
    info->previous_total_cpu_time = info->total_cpu_time;
    info->previous_total_idle_time = info->total_idle_time;

    // Return the CPU usage percentage
    return cpu_usage;
}

// Print CPU usage information
void print_cpu_usage_info(cpu_usage_info_t *info, double cpu_usage) {
    printf("Total CPU time: %lld\n", info->total_cpu_time);
    printf("Total idle time: %lld\n", info->total_idle_time);
    printf("CPU usage: %.2f%%\n", cpu_usage);
}

// Main function
int main(int argc, char *argv[]) {
    // Initialize the CPU usage information structure
    cpu_usage_info_t info;
    info.total_cpu_time = 0;
    info.total_idle_time = 0;
    info.previous_total_cpu_time = 0;
    info.previous_total_idle_time = 0;

    // Get CPU usage information
    get_cpu_usage_info(&info);

    // Calculate CPU usage percentage
    double cpu_usage = calculate_cpu_usage(&info);

    // Print CPU usage information
    print_cpu_usage_info(&info, cpu_usage);

    return EXIT_SUCCESS;
}