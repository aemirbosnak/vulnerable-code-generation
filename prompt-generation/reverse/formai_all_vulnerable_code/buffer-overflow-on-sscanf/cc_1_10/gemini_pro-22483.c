//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the memory usage information
typedef struct {
    long long total_memory;
    long long free_memory;
    long long used_memory;
    long long shared_memory;
    long long buff_cache;
} memory_usage_t;

// Function to get the memory usage information
memory_usage_t get_memory_usage() {
    memory_usage_t usage;
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line, "MemTotal: %llu kB", &usage.total_memory);
        } else if (strncmp(line, "MemFree:", 8) == 0) {
            sscanf(line, "MemFree: %llu kB", &usage.free_memory);
        } else if (strncmp(line, "MemUsed:", 8) == 0) {
            sscanf(line, "MemUsed: %llu kB", &usage.used_memory);
        } else if (strncmp(line, "SharedMem:", 10) == 0) {
            sscanf(line, "SharedMem: %llu kB", &usage.shared_memory);
        } else if (strncmp(line, "BuffCache:", 10) == 0) {
            sscanf(line, "BuffCache: %llu kB", &usage.buff_cache);
        }
    }

    fclose(fp);

    return usage;
}

// Function to print the memory usage information
void print_memory_usage(memory_usage_t usage) {
    printf("Total memory: %llu kB\n", usage.total_memory);
    printf("Free memory: %llu kB\n", usage.free_memory);
    printf("Used memory: %llu kB\n", usage.used_memory);
    printf("Shared memory: %llu kB\n", usage.shared_memory);
    printf("Buff/cache: %llu kB\n", usage.buff_cache);
}

// Main function
int main(int argc, char *argv[]) {
    // Get the memory usage information
    memory_usage_t usage = get_memory_usage();

    // Print the memory usage information
    print_memory_usage(usage);

    return 0;
}