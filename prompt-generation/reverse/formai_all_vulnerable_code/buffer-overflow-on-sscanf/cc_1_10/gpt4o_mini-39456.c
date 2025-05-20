//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// A function that reads and parses the memory information from /proc/meminfo
void read_memory_info(long *total, long *free, long *available, long *buffers, long *cached) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", total) == 1) continue;
        if (sscanf(line, "MemFree: %ld kB", free) == 1) continue;
        if (sscanf(line, "MemAvailable: %ld kB", available) == 1) continue;
        if (sscanf(line, "Buffers: %ld kB", buffers) == 1) continue;
        if (sscanf(line, "Cached: %ld kB", cached) == 1) continue;
    }
    
    fclose(file);
}

// A function to convert kilobytes to gigabytes for easier representation
double kB_to_GB(long kB) {
    return kB / 1024.0 / 1024.0;
}

// A function to display the memory details
void display_memory_info(long total, long free, long available, long buffers, long cached) {
    printf("\n--- Memory Usage ---\n");
    printf("Total Memory: %.2f GB\n", kB_to_GB(total));
    printf("Free Memory: %.2f GB\n", kB_to_GB(free));
    printf("Available Memory: %.2f GB\n", kB_to_GB(available));
    printf("Buffers: %.2f GB\n", kB_to_GB(buffers));
    printf("Cached: %.2f GB\n", kB_to_GB(cached));
    printf("Memory Used: %.2f GB\n", kB_to_GB(total - free));
    printf("---------------------\n");
}

// The main function serves as the entry point for the program
int main() {
    long total, free, available, buffers, cached;

    while (1) {
        // Clear the console
        system("clear");
        
        // Read memory information
        read_memory_info(&total, &free, &available, &buffers, &cached);
        
        // Display memory information
        display_memory_info(total, free, available, buffers, cached);
        
        // Sleep for a while before the next refresh
        sleep(3);
    }

    return 0; // Though unreachable, adheres to the standard main function
}