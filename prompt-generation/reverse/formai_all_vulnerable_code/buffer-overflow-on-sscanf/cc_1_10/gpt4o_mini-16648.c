//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256

void display_memory_usage() {
    // Command to retrieve memory usage information
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    size_t total_memory = 0, free_memory = 0, used_memory = 0;

    // Open the file containing memory info
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read the memory info line by line
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "MemTotal: %zu kB", &total_memory) == 1) {
            // Total memory found
        } else if (sscanf(line, "MemFree: %zu kB", &free_memory) == 1) {
            // Free memory found
        }
    }
    fclose(fp);

    // Calculate used memory
    used_memory = total_memory - free_memory;

    // Convert from kB to MB
    total_memory /= 1024;
    free_memory /= 1024;
    used_memory /= 1024;

    // Display memory usage
    printf("Memory Usage:\n");
    printf("Total Memory: %zu MB\n", total_memory);
    printf("Free Memory: %zu MB\n", free_memory);
    printf("Used Memory: %zu MB\n", used_memory);
}

void display_memory_percentage(size_t total_memory, size_t used_memory) {
    // Calculate and display memory percentage
    float percentage_used = ((float)used_memory / total_memory) * 100;
    printf("Memory Percentage Used: %.2f%%\n", percentage_used);
}

int main() {
    // Variables to hold memory values
    size_t total_memory, free_memory, used_memory;

    // Display initial memory usage
    display_memory_usage();
    
    // Continuously monitor memory usage every second
    while (1) {
        printf("\nMonitoring memory usage...\n");
        sleep(1); // Sleep for 1 second

        // Fetch memory data again
        FILE *fp = fopen("/proc/meminfo", "r");
        char line[MAX_LINE_LENGTH];
        total_memory = free_memory = used_memory = 0;

        if (fp == NULL) {
            perror("Failed to open /proc/meminfo");
            exit(EXIT_FAILURE);
        }

        while (fgets(line, sizeof(line), fp) != NULL) {
            if (sscanf(line, "MemTotal: %zu kB", &total_memory) == 1) {}
            else if (sscanf(line, "MemFree: %zu kB", &free_memory) == 1) {}
        }
        fclose(fp);

        used_memory = total_memory - free_memory;

        // Convert to MB
        total_memory /= 1024;
        free_memory /= 1024;
        used_memory /= 1024;

        // Display the updated memory usage
        printf("Total Memory: %zu MB | Free Memory: %zu MB | Used Memory: %zu MB\n",
               total_memory, free_memory, used_memory);
        display_memory_percentage(total_memory, used_memory);
    }

    return 0;
}