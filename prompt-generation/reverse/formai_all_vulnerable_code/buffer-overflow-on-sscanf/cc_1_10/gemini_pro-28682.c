//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// Define the struct for the RAM usage information
typedef struct ram_usage {
    unsigned long total;
    unsigned long free;
    unsigned long used;
    unsigned long buffcache;
} ram_usage;

// Function to get the RAM usage information
int get_ram_usage(ram_usage *usage) {
    // Open the /proc/meminfo file
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        return -1;
    }

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Parse the line to get the RAM usage information
        if (sscanf(line, "MemTotal: %lu kB", &usage->total) == 1) {
            continue;
        } else if (sscanf(line, "MemFree: %lu kB", &usage->free) == 1) {
            continue;
        } else if (sscanf(line, "MemAvailable: %lu kB", &usage->buffcache) == 1) {
            continue;
        } else if (sscanf(line, "Buffers: %lu kB", &usage->buffcache) == 1) {
            continue;
        } else if (sscanf(line, "Cached: %lu kB", &usage->buffcache) == 1) {
            continue;
        }
    }

    // Close the file
    fclose(file);

    // Calculate the used RAM
    usage->used = usage->total - usage->free;

    // Return 0 if successful
    return 0;
}

// Function to print the RAM usage information
void print_ram_usage(ram_usage *usage) {
    printf("Total RAM: %lu KB\n", usage->total);
    printf("Free RAM: %lu KB\n", usage->free);
    printf("Used RAM: %lu KB\n", usage->used);
    printf("Buffers and Cache: %lu KB\n", usage->buffcache);
}

// Main function
int main(int argc, char **argv) {
    // Get the RAM usage information
    ram_usage usage;
    if (get_ram_usage(&usage) != 0) {
        fprintf(stderr, "Error getting RAM usage information\n");
        return 1;
    }

    // Print the RAM usage information
    print_ram_usage(&usage);

    return 0;
}