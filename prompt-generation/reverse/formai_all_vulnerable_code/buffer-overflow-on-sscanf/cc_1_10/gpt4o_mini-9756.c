//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MEMINFO "/proc/meminfo"
#define BUFFER_SIZE 256

typedef struct MemoryInfo {
    long total;
    long free;
    long available;
    long buffered;
    long cached;
} MemoryInfo;

void clearScreen() {
    // Clear terminal screen
    printf("\033[H\033[J");
}

void displayHeader() {
    printf("*************************************\n");
    printf("*      RAM Usage Monitor v1.0       *\n");
    printf("*************************************\n\n");
}

void parseMemoryInfo(MemoryInfo *memInfo) {
    FILE *file = fopen(MEMINFO, "r");
    if (file == NULL) {
        perror("Unable to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &memInfo->total) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %ld kB", &memInfo->free) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemAvailable: %ld kB", &memInfo->available) == 1) {
            continue;
        }
        if (sscanf(buffer, "Buffers: %ld kB", &memInfo->buffered) == 1) {
            continue;
        }
        if (sscanf(buffer, "Cached: %ld kB", &memInfo->cached) == 1) {
            continue;
        }
    }

    fclose(file);
}

void displayMemoryUsage(const MemoryInfo *memInfo) {
    long usedMemory = memInfo->total - memInfo->free;

    printf("Total Memory: %ld kB\n", memInfo->total);
    printf("Free Memory: %ld kB\n", memInfo->free);
    printf("Used Memory: %ld kB\n", usedMemory);
    printf("Available Memory: %ld kB\n", memInfo->available);
    printf("Buffered Memory: %ld kB\n", memInfo->buffered);
    printf("Cached Memory: %ld kB\n\n", memInfo->cached);
}

void displayMemoryPercentage(const MemoryInfo *memInfo) {
    double total = memInfo->total;
    double used = total - memInfo->free;
    double usedPercentage = (used / total) * 100;

    printf("Memory Usage: %.2f%%\n", usedPercentage);
}

void monitorMemoryUsage() {
    MemoryInfo memInfo;
    
    while (1) {
        clearScreen();
        displayHeader();
        parseMemoryInfo(&memInfo);
        displayMemoryUsage(&memInfo);
        displayMemoryPercentage(&memInfo);
        sleep(3);  // Refresh every 3 seconds
    }
}

int main() {
    monitorMemoryUsage();
    return 0; // This line is never reached, but it's good practice
}