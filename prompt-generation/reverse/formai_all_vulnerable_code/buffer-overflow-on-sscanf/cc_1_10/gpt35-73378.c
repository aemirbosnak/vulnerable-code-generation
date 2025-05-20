//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Function to get total system memory
double get_total_memory() {
    char buffer[MAX_LINE_LENGTH];
    double total_memory;

    FILE* fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/meminfo\n");
        exit(1);
    }

    // Parse the first line to get total memory
    fgets(buffer, MAX_LINE_LENGTH, fp);
    sscanf(buffer, "MemTotal: %lf kB", &total_memory);

    // Convert to GB
    total_memory /= 1024*1024;

    fclose(fp);
    return total_memory;
}

// Function to get current RAM usage
double get_current_memory_usage() {
    char buffer[MAX_LINE_LENGTH];
    double memory_usage;

    FILE* fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/meminfo\n");
        exit(1);
    }

    // Parse the second line to get current memory usage
    fgets(buffer, MAX_LINE_LENGTH, fp);
    fgets(buffer, MAX_LINE_LENGTH, fp);
    sscanf(buffer, "MemAvailable: %lf kB", &memory_usage);

    // Convert to GB
    memory_usage /= 1024*1024;

    fclose(fp);
    return memory_usage;
}

// Main function
int main() {
    double total_memory, current_memory_usage;
    int i = 0;

    // Get total memory and print it
    total_memory = get_total_memory();
    printf("Total system memory: %.2lf GB\n\n", total_memory);

    // Print RAM usage every second for 10 seconds
    while (i < 10) {
        // Get current memory usage
        current_memory_usage = get_current_memory_usage();

        // Print current memory usage
        printf("Current RAM usage: %.2lf GB\n", current_memory_usage);
        
        // Sleep for 1 second
        sleep(1);

        i++;
    }

    return 0;
}