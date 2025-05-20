//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
#define SLEEP_INTERVAL 2

void clearConsole() {
    // Clear the console output
    printf("\033[H\033[J");
}

void getMemoryUsage(double* total, double* used) {
    FILE* file;
    char buffer[BUFFER_SIZE];
    double memTotal = 0.0, memFree = 0.0, memAvailable = 0.0;

    // Open the /proc/meminfo file to read memory information
    file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    // Read each line from meminfo
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (sscanf(buffer, "MemTotal: %lf kB", &memTotal)) continue;
        if (sscanf(buffer, "MemFree: %lf kB", &memFree)) continue;
        if (sscanf(buffer, "MemAvailable: %lf kB", &memAvailable)) continue;
    }

    fclose(file);

    // Calculate used and total memory in megabytes
    *total = memTotal / 1024;  // Convert to MB
    *used = (memTotal - memFree) / 1024;  // Convert to MB
}

void displayMemoryUsage(double total, double used) {
    // Calculate percentage of used memory
    double usedPercentage = (used / total) * 100;

    // Display memory usage
    printf("Total RAM: %.2f MB\n", total);
    printf("Used RAM: %.2f MB (%.2f%%)\n", used, usedPercentage);
  
    // Create a simple bar graph representation
    int barWidth = 50;
    int filledWidth = (int)(usedPercentage / 100 * barWidth);

    printf("Memory Usage: [");
    for (int i = 0; i < filledWidth; i++) {
        printf("=");
    }
    for (int i = filledWidth; i < barWidth; i++) {
        printf(" ");
    }
    printf("] %.2f MB\n", used);
}

int main() {
    double totalMemory, usedMemory;

    // Run indefinitely until interrupted
    while (1) {
        clearConsole();
        getMemoryUsage(&totalMemory, &usedMemory);
        displayMemoryUsage(totalMemory, usedMemory);
        sleep(SLEEP_INTERVAL);  // Wait for the defined interval before next check
    }

    return 0;
}