//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void clear_screen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void display_memory_info() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    long total_memory, free_memory, available_memory;

    // Open the proc filesystem to read the memory info
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to read /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read the memory info
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemAvailable: %ld kB", &available_memory) == 1) {
            continue;
        }
    }
    
    fclose(fp);

    // Calculate used memory
    long used_memory = total_memory - free_memory;
    double used_percentage = ((double)used_memory / total_memory) * 100.0;

    // Display the information
    printf("\n--- RAM Usage Monitor ---\n");
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Available Memory: %ld kB\n", available_memory);
    printf("Used Memory: %ld kB (%.2f%%)\n", used_memory, used_percentage);
    printf("-------------------------\n");
}

int main() {
    printf("Welcome to the RAM Usage Monitor!\n");
    printf("Press Ctrl+C to exit at any time.\n");
    
    while (1) {
        clear_screen();
        display_memory_info();
        
        // Sleep for 2 seconds before refreshing
        sleep(2);
    }

    return 0;
}