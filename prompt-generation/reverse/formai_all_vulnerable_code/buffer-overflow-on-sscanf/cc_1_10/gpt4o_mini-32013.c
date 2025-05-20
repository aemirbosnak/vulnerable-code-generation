//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void displayMemoryUsage() {
    FILE *fp;
    char buffer[256];
    long totalMemory = 0, freeMemory = 0, buffers = 0, cached = 0, usedMemory = 0;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &totalMemory) == 1) {
            totalMemory /= 1024;  // Convert to MB
        } else if (sscanf(buffer, "MemFree: %ld kB", &freeMemory) == 1) {
            freeMemory /= 1024;  // Convert to MB
        } else if (sscanf(buffer, "Buffers: %ld kB", &buffers) == 1) {
            buffers /= 1024;  // Convert to MB
        } else if (sscanf(buffer, "Cached: %ld kB", &cached) == 1) {
            cached /= 1024;  // Convert to MB
        }
    }
    fclose(fp);

    usedMemory = totalMemory - freeMemory - buffers - cached;
    float usedMemoryPercentage = (float)usedMemory / (float)totalMemory * 100;

    printf("Total Memory:   %ld MB\n", totalMemory);
    printf("Free Memory:    %ld MB\n", freeMemory);
    printf("Used Memory:    %ld MB\n", usedMemory);
    printf("Used Memory %%:  %.2f%%\n", usedMemoryPercentage);
}

void displayMemoryUsageContinuous(int interval) {
    while (1) {
        system("clear");  // Clear the screen for better visibility
        displayMemoryUsage();
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    int interval = 5;  // Default interval in seconds

    if (argc > 1) {
        interval = atoi(argv[1]);
    } 
    if (interval < 1) {
        fprintf(stderr, "Interval must be at least 1 second.\n");
        return EXIT_FAILURE;
    }

    printf("RAM Usage Monitor\n");
    printf("Refresh Interval: %d seconds\n", interval);
    printf("Press Ctrl+C to stop.\n");
    
    displayMemoryUsageContinuous(interval);
    
    return EXIT_SUCCESS;
}