//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void displayMemoryUsage() {
    FILE *fp;
    char buffer[256];
    long totalMemory = 0, freeMemory = 0, availableMemory = 0;

    // Open /proc/meminfo to read memory status
    if ((fp = fopen("/proc/meminfo", "r")) == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read memory information from file
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (sscanf(buffer, "MemTotal: %ld kB", &totalMemory) == 1) {
            // Get total memory
        } else if (sscanf(buffer, "MemFree: %ld kB", &freeMemory) == 1) {
            // Get free memory
        } else if (sscanf(buffer, "MemAvailable: %ld kB", &availableMemory) == 1) {
            // Get available memory
        }
    }
    fclose(fp);

    // Calculate used memory
    long usedMemory = totalMemory - freeMemory;

    // Display memory usage
    printf("\n-------------------------------------\n");
    printf("Total Memory: %ld kB\n", totalMemory);
    printf("Free Memory: %ld kB\n", freeMemory);
    printf("Available Memory: %ld kB\n", availableMemory);
    printf("Used Memory: %ld kB\n", usedMemory);
    printf("-------------------------------------\n");
}

int main() {
    // Loop for continuously monitoring memory usage
    while (1) {
        displayMemoryUsage();
        sleep(2);  // Pause for 2 seconds before the next update
    }
    
    return 0;
}