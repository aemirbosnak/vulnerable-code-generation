//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define KB 1024
#define MB 1024 * KB
#define GB 1024 * MB

// Calculate the RAM usage in bytes
unsigned long long calculateRAMUsage() {
    FILE *fp;
    char buffer[1024];
    unsigned long long totalRAM = 0;
    unsigned long long freeRAM = 0;

    // Open the file "/proc/meminfo"
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        return 0;
    }

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Parse the line and extract the RAM usage
        if (sscanf(buffer, "MemTotal: %llu kB", &totalRAM) == 1) {
            totalRAM *= KB;
        } else if (sscanf(buffer, "MemFree: %llu kB", &freeRAM) == 1) {
            freeRAM *= KB;
        }
    }

    // Close the file
    fclose(fp);

    // Calculate the RAM usage
    unsigned long long ramUsage = totalRAM - freeRAM;

    return ramUsage;
}

// Print the RAM usage in a mathematical style
void printRAMUsage(unsigned long long ramUsage) {
    if (ramUsage < MB) {
        printf("RAM Usage: %.2f KB\n", (double)ramUsage / KB);
    } else if (ramUsage < GB) {
        printf("RAM Usage: %.2f MB\n", (double)ramUsage / MB);
    } else {
        printf("RAM Usage: %.2f GB\n", (double)ramUsage / GB);
    }
}

int main() {
    // Calculate the RAM usage
    unsigned long long ramUsage = calculateRAMUsage();

    // Print the RAM usage
    printRAMUsage(ramUsage);

    return 0;
}