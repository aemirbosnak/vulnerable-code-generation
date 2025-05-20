//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Structure to hold RAM usage information
typedef struct {
    size_t total;           // Total RAM size in bytes
    size_t free;            // Free RAM size in bytes
    size_t used;            // Used RAM size in bytes
    double percentage;     // Percentage of RAM used
} ram_usage_t;

// Function to get RAM usage information
ram_usage_t get_ram_usage() {
    ram_usage_t usage;

    // Open the /proc/meminfo file
    FILE *f = fopen("/proc/meminfo", "r");
    if (f == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read the first line of the file (total RAM)
    fscanf(f, "MemTotal: %lu kB", &usage.total);

    // Read the second line of the file (free RAM)
    fscanf(f, "MemFree: %lu kB", &usage.free);

    // Calculate the used RAM
    usage.used = usage.total - usage.free;

    // Calculate the percentage of RAM used
    usage.percentage = (double) usage.used / usage.total * 100;

    // Close the file
    fclose(f);

    return usage;
}

// Function to print RAM usage information
void print_ram_usage(ram_usage_t usage) {
    printf("RAM usage information:\n");
    printf("Total RAM: %.2f MB\n", usage.total / 1024.0);
    printf("Free RAM: %.2f MB\n", usage.free / 1024.0);
    printf("Used RAM: %.2f MB\n", usage.used / 1024.0);
    printf("Percentage of RAM used: %.2f%%\n", usage.percentage);
}

int main() {
    // Get RAM usage information
    ram_usage_t usage = get_ram_usage();

    // Print RAM usage information
    print_ram_usage(usage);

    return 0;
}