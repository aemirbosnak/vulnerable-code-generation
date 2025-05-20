//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void display_memory_usage() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    long total_memory = 0;
    long free_memory = 0;
    long available_memory = 0;
    long used_memory = 0;

    // Open the meminfo file to read memory statistics
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read the memory information line by line
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {
            total_memory *= 1024; // Convert to bytes
        } else if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {
            free_memory *= 1024; // Convert to bytes
        } else if (sscanf(buffer, "MemAvailable: %ld kB", &available_memory) == 1) {
            available_memory *= 1024; // Convert to bytes
        }
    }

    fclose(file);
    
    // Calculate used memory
    used_memory = total_memory - free_memory;

    // Display memory usage details
    printf("Memory Usage Monitor\n");
    printf("============================\n");
    printf("Total Memory:      %ld bytes (%ld MB)\n", total_memory, total_memory / (1024 * 1024));
    printf("Free Memory:       %ld bytes (%ld MB)\n", free_memory, free_memory / (1024 * 1024));
    printf("Available Memory:  %ld bytes (%ld MB)\n", available_memory, available_memory / (1024 * 1024));
    printf("Used Memory:       %ld bytes (%ld MB)\n", used_memory, used_memory / (1024 * 1024));
    printf("============================\n");
}

int main() {
    // Execute the memory usage display function
    display_memory_usage();
    return 0;
}