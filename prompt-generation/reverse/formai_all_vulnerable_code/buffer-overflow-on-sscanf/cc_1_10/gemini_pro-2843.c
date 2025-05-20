//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define the struct to store the memory usage information
typedef struct {
    size_t total;
    size_t used;
    size_t free;
} MemoryUsage;

// Get the memory usage information
void getMemoryUsage(MemoryUsage *usage) {
    // Open the /proc/meminfo file
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        return;
    }

    // Read the first line of the file
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("Error reading /proc/meminfo");
        fclose(fp);
        return;
    }

    // Parse the first line of the file to get the total memory
    sscanf(line, "MemTotal: %zu kB", &usage->total);

    // Read the second line of the file
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("Error reading /proc/meminfo");
        fclose(fp);
        return;
    }

    // Parse the second line of the file to get the used memory
    sscanf(line, "MemFree: %zu kB", &usage->free);

    // Calculate the used memory
    usage->used = usage->total - usage->free;

    // Close the file
    fclose(fp);
}

// Print the memory usage information
void printMemoryUsage(MemoryUsage *usage) {
    printf("Total memory: %zu kB\n", usage->total);
    printf("Used memory: %zu kB\n", usage->used);
    printf("Free memory: %zu kB\n", usage->free);
}

// Main function
int main() {
    // Get the memory usage information
    MemoryUsage usage;
    getMemoryUsage(&usage);

    // Print the memory usage information
    printMemoryUsage(&usage);

    return 0;
}