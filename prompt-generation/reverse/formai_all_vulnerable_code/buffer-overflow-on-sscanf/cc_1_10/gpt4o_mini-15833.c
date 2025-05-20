//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

// Structure to hold memory usage data
typedef struct {
    long total;
    long free;
    long available;
    long buffers;
    long cached;
    long swap_total;
    long swap_free;
} MemoryUsage;

// Function to read memory usage from /proc/meminfo
MemoryUsage get_memory_usage() {
    MemoryUsage mem_usage;
    char buffer[BUFFER_SIZE];
    FILE* meminfo_file = fopen("/proc/meminfo", "r");

    if (meminfo_file == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, meminfo_file)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &mem_usage.total) == 1) continue;
        if (sscanf(buffer, "MemFree: %ld kB", &mem_usage.free) == 1) continue;
        if (sscanf(buffer, "MemAvailable: %ld kB", &mem_usage.available) == 1) continue;
        if (sscanf(buffer, "Buffers: %ld kB", &mem_usage.buffers) == 1) continue;
        if (sscanf(buffer, "Cached: %ld kB", &mem_usage.cached) == 1) continue;
        if (sscanf(buffer, "SwapTotal: %ld kB", &mem_usage.swap_total) == 1) continue;
        if (sscanf(buffer, "SwapFree: %ld kB", &mem_usage.swap_free) == 1) continue;
    }

    fclose(meminfo_file);
    return mem_usage;
}

// Function to display memory usage statistics
void display_memory_usage(MemoryUsage mem_usage) {
    printf("\n---------- Memory Usage Statistics ----------\n");
    printf("Total Memory: %ld kB\n", mem_usage.total);
    printf("Free Memory: %ld kB\n", mem_usage.free);
    printf("Available Memory: %ld kB\n", mem_usage.available);
    printf("Buffers: %ld kB\n", mem_usage.buffers);
    printf("Cached: %ld kB\n", mem_usage.cached);
    printf("Total Swap: %ld kB\n", mem_usage.swap_total);
    printf("Free Swap: %ld kB\n", mem_usage.swap_free);
    printf("---------------------------------------------\n");
}

// Main function
int main() {
    MemoryUsage mem_usage;
    int refresh_interval = 5;  // Refresh every 5 seconds

    printf("RAM Usage Monitor - Press Ctrl+C to exit\n");

    while (1) {
        mem_usage = get_memory_usage();
        display_memory_usage(mem_usage);
        sleep(refresh_interval);
    }

    return 0;
}