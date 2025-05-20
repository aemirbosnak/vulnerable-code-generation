//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Structure to store RAM usage information
typedef struct {
    unsigned long total;      // Total RAM size in bytes
    unsigned long free;       // Free RAM size in bytes
    unsigned long buffers;   // Buffers RAM size in bytes
    unsigned long cached;    // Cached RAM size in bytes
} ram_usage_t;

// Function to get RAM usage information
int get_ram_usage(ram_usage_t *usage) {
    // Open the /proc/meminfo file
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the line and store the RAM usage information
        if (sscanf(line, "MemTotal: %ld kB", &usage->total) == 1) {
            usage->total *= 1024;
        } else if (sscanf(line, "MemFree: %ld kB", &usage->free) == 1) {
            usage->free *= 1024;
        } else if (sscanf(line, "Buffers: %ld kB", &usage->buffers) == 1) {
            usage->buffers *= 1024;
        } else if (sscanf(line, "Cached: %ld kB", &usage->cached) == 1) {
            usage->cached *= 1024;
        }
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Function to print RAM usage information
void print_ram_usage(ram_usage_t *usage) {
    printf("Total RAM: %ld bytes\n", usage->total);
    printf("Free RAM: %ld bytes\n", usage->free);
    printf("Buffers RAM: %ld bytes\n", usage->buffers);
    printf("Cached RAM: %ld bytes\n", usage->cached);
    printf("Used RAM: %ld bytes\n", usage->total - usage->free);
}

// Main function
int main(void) {
    // Get RAM usage information
    ram_usage_t usage;
    if (get_ram_usage(&usage) != 0) {
        return EXIT_FAILURE;
    }

    // Print RAM usage information
    print_ram_usage(&usage);

    return EXIT_SUCCESS;
}