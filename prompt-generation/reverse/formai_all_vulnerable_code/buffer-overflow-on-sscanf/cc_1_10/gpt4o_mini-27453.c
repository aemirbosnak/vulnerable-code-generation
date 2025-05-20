//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LINE_SIZE 256

// Function to read the memory usage from the /proc/meminfo file
void read_memory_usage(double *total_memory, double *free_memory, double *used_memory) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[LINE_SIZE];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %lf kB", total_memory) == 1) {
            *total_memory /= 1024; // Convert to MB
        }
        if (sscanf(line, "MemFree: %lf kB", free_memory) == 1) {
            *free_memory /= 1024; // Convert to MB
        }
        // Stop reading once we have both values
        if (*total_memory && *free_memory) {
            break;
        }
    }
    fclose(file);

    *used_memory = *total_memory - *free_memory;
}

// Function to get RAM usage percentage
double calculate_ram_usage_percentage(double total, double used) {
    if (total == 0.0) return 0.0;
    return (used / total) * 100;
}

// Function to print memory usage in an organized manner
void print_memory_usage(double total_memory, double free_memory, double used_memory) {
    printf("\n=== RAM Usage Monitor ===\n");
    printf("Total RAM: %.2f MB\n", total_memory);
    printf("Free RAM: %.2f MB\n", free_memory);
    printf("Used RAM: %.2f MB\n", used_memory);
    printf("Used RAM Percentage: %.2f %%\n", calculate_ram_usage_percentage(total_memory, used_memory));
    printf("===========================\n");
}

// Main function to continuously monitor RAM usage
int main() {
    double total_memory = 0.0, free_memory = 0.0, used_memory = 0.0;

    while (1) {
        read_memory_usage(&total_memory, &free_memory, &used_memory);
        print_memory_usage(total_memory, free_memory, used_memory);
        
        // Sleep for 5 seconds before the next update
        sleep(5);
    }

    return 0;
}