//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to get the current memory usage
void get_memory_usage(long *used_memory, long *free_memory) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", used_memory) == 1) {
            // Successfully read total memory
        }
        if (sscanf(line, "MemFree: %ld kB", free_memory) == 1) {
            // Successfully read free memory
        }
    }

    fclose(file);
}

// Function to calculate used memory
long calculate_used_memory(long total_memory, long free_memory) {
    return total_memory - free_memory;
}

// Function to display memory usage
void display_memory_usage(long total_memory, long free_memory, long used_memory) {
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Used Memory: %ld kB\n", used_memory);
    printf("Memory Usage Percentage: %.2f%%\n", (used_memory / (double)total_memory) * 100);
}

int main() {
    long total_memory = 0;
    long free_memory = 0;

    // Get the memory information
    get_memory_usage(&total_memory, &free_memory);

    // Calculate used memory
    long used_memory = calculate_used_memory(total_memory, free_memory);

    // Display the memory usage information
    display_memory_usage(total_memory, free_memory, used_memory);

    // Monitor memory usage continuously every 5 seconds
    while (1) {
        sleep(5);
        printf("\n--- Updating Memory Usage ---\n");
        get_memory_usage(&total_memory, &free_memory);
        used_memory = calculate_used_memory(total_memory, free_memory);
        display_memory_usage(total_memory, free_memory, used_memory);
    }

    return 0;
}