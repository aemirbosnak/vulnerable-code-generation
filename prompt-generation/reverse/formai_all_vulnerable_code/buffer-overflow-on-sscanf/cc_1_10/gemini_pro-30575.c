//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#define PAGE_SIZE 4096
#define MB_SIZE (1024 * 1024)

// Define a custom data structure to store memory usage information
typedef struct memory_usage {
    size_t total_memory;
    size_t used_memory;
    size_t free_memory;
} memory_usage_t;

// Function to get the current memory usage
memory_usage_t get_memory_usage() {
    memory_usage_t usage;

    // Open /proc/meminfo and read the relevant lines
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line + 9, "%lu", &usage.total_memory);
        } else if (strncmp(line, "MemFree:", 8) == 0) {
            sscanf(line + 8, "%lu", &usage.free_memory);
        } else if (strncmp(line, "Buffers:", 8) == 0) {
            sscanf(line + 8, "%lu", &usage.used_memory);
        } else if (strncmp(line, "Cached:", 7) == 0) {
            sscanf(line + 7, "%lu", &usage.used_memory);
        }
    }

    fclose(fp);

    // Calculate the used memory and return the usage
    usage.used_memory = usage.total_memory - usage.free_memory;
    return usage;
}

// Main function
int main(int argc, char *argv[]) {
    // Get the current memory usage
    memory_usage_t usage = get_memory_usage();

    // Print the memory usage in a readable format
    printf("Total memory: %lu MB\n", usage.total_memory / MB_SIZE);
    printf("Used memory: %lu MB\n", usage.used_memory / MB_SIZE);
    printf("Free memory: %lu MB\n", usage.free_memory / MB_SIZE);

    return EXIT_SUCCESS;
}