//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LINE_SIZE 256
#define MEMINFO_FILE "/proc/meminfo"

void display_memory_usage() {
    FILE *meminfo;
    char line[LINE_SIZE];
    long total_memory = 0;
    long free_memory = 0;
    long available_memory = 0;

    // Open meminfo file to read memory usage
    meminfo = fopen(MEMINFO_FILE, "r");
    if (meminfo == NULL) {
        fprintf(stderr, "Could not open %s for reading.\n", MEMINFO_FILE);
        return;
    }

    // Read the relevant memory information
    while (fgets(line, sizeof(line), meminfo)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_memory) == 1) {
            // Total memory read successfully
        }
        else if (sscanf(line, "MemFree: %ld kB", &free_memory) == 1) {
            // Free memory read successfully
        }
        else if (sscanf(line, "MemAvailable: %ld kB", &available_memory) == 1) {
            // Available memory read successfully
        }
    }
    
    // Close the memory info file
    fclose(meminfo);
    
    // Calculate used memory
    long used_memory = total_memory - free_memory;
    
    // Display the memory information in a peaceful and informative manner
    printf("\n🧘‍♂️ Peaceful Memory Usage Monitor 🧘‍♀️\n");
    printf("-------------------------------------\n");
    printf("Total Memory:     %ld kB\n", total_memory);
    printf("Free Memory:      %ld kB\n", free_memory);
    printf("Available Memory: %ld kB\n", available_memory);
    printf("Used Memory:      %ld kB\n", used_memory);
    printf("-------------------------------------\n");
    
    // Display percentage usage
    double usage_percentage = (double)used_memory / total_memory * 100;
    printf("Memory Usage:     %.2f%%\n", usage_percentage);
    printf("-------------------------------------\n");
}

int main() {
    while (1) {
        display_memory_usage();
        printf("\n🌱 Peacefully waiting for 5 seconds...\n");
        sleep(5); // Wait for 5 seconds before refreshing
    }

    return 0;
}