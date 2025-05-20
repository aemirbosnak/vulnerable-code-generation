//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Structure to hold memory usage data
typedef struct {
    long total;
    long used;
    long free;
} MemoryUsage;

// Function to parse memory information
MemoryUsage get_memory_usage() {
    MemoryUsage mem_usage;
    
    // Open the /proc/meminfo file
    FILE* meminfo_file = fopen("/proc/meminfo", "r");
    if (meminfo_file == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }
    
    char line[256];
    // Read through the meminfo file
    while (fgets(line, sizeof(line), meminfo_file)) {
        // Parsing total RAM
        if (sscanf(line, "MemTotal: %ld kB", &mem_usage.total) == 1) {
            // Do nothing; total is captured
        }
        // Parsing free RAM
        else if (sscanf(line, "MemFree: %ld kB", &mem_usage.free) == 1) {
            // Do nothing; free is captured
        }
        // Parsing buffers
        else if (sscanf(line, "Buffers: %ld kB", &mem_usage.used) == 1) {
            mem_usage.used = mem_usage.total - mem_usage.free; // Simple calculation
        }
    }
    // Close the file
    fclose(meminfo_file);
    
    // Calculate used memory correctly
    mem_usage.used = mem_usage.total - mem_usage.free;

    return mem_usage;
}

// Function to display memory usage
void display_memory_usage(MemoryUsage mem_usage) {
    printf("\n~~~~~~~~~~~ Memory Usage ~~~~~~~~~~~\n");
    printf("Total Memory:    %ld kB\n", mem_usage.total);
    printf("Used Memory:     %ld kB\n", mem_usage.used);
    printf("Free Memory:     %ld kB\n", mem_usage.free);
    printf("=====================================\n");
}

// Main function
int main() {
    // Loop indefinitely
    while (1) {
        // Get memory usage stats
        MemoryUsage mem_usage = get_memory_usage();
        
        // Display the results
        display_memory_usage(mem_usage);
        
        // Sleep for 5 seconds before next update
        sleep(5);
        
        // Clear the console
        printf("\033[H\033[J");  // ANSI escape codes to clear the screen
    }

    return 0;
}