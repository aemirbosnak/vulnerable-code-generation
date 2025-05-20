//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void displayMemoryUsage() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    char line[256];
    long totalMemory = 0;
    long freeMemory = 0;
    long availableMemory = 0;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", &totalMemory) == 1) {
            // Total memory found
        } else if (sscanf(line, "MemFree: %ld kB", &freeMemory) == 1) {
            // Free memory found
        } else if (sscanf(line, "MemAvailable: %ld kB", &availableMemory) == 1) {
            // Available memory found
        }
    }

    fclose(file);

    // Calculate used memory
    long usedMemory = totalMemory - freeMemory;

    // Convert to MB for easier readability
    totalMemory /= 1024;
    usedMemory /= 1024;
    freeMemory /= 1024;
    availableMemory /= 1024;

    clearScreen();
    
    // Display memory usage
    printf("╔══════════════════════════════════╗\n");
    printf("║          RAM Usage Monitor      ║\n");
    printf("╚══════════════════════════════════╝\n");
    printf("Total Memory:    %ld MB\n", totalMemory);
    printf("Used Memory:     %ld MB\n", usedMemory);
    printf("Free Memory:     %ld MB\n", freeMemory);
    printf("Available Memory: %ld MB\n", availableMemory);
    printf("╚══════════════════════════════════╝\n");
}

int main() {
    while (1) {
        displayMemoryUsage();
        sleep(2); // Update every 2 seconds
    }

    return 0;
}