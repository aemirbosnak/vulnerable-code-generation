//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to get memory information
void get_memory_info() {
    FILE *file;
    char buffer[256];
    long total_memory = 0, free_memory = 0;

    // Open the /proc/meminfo file
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read the information
    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "MemTotal: %ld", &total_memory) == 1) {
            // Total memory found
        } else if (sscanf(buffer, "MemFree: %ld", &free_memory) == 1) {
            // Free memory found
        }
        
        // Break if both values have been found
        if (total_memory > 0 && free_memory > 0) {
            break;
        }
    }

    fclose(file);

    // Calculate used memory
    long used_memory = total_memory - free_memory;

    // Print the memory usage
    printf("\033[1;32mTotal Memory: \033[0m%ld kB\n", total_memory);
    printf("\033[1;34mFree Memory: \033[0m%ld kB\n", free_memory);
    printf("\033[1;31mUsed Memory: \033[0m%ld kB\n", used_memory);
    printf("\033[1;35mMemory Usage: \033[0m%.2f%%\n", (float)used_memory / total_memory * 100);
    printf("\n");
}

int main() {
    // Start monitoring memory usage every 2 seconds
    printf("---- RAM Usage Monitor ----\n");
    printf("Press Ctrl+C to exit the monitor.\n\n");

    while (1) {
        // Clear the terminal screen for a cleaner output
        printf("\033[H\033[J");
        
        // Get and display memory information
        get_memory_info();
        
        // Sleep for 2 seconds
        sleep(2);
    }

    return 0;
}