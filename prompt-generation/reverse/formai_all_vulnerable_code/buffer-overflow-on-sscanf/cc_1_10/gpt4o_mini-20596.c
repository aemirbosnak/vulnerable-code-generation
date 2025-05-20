//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define REPEAT_DELAY 2

void clear_console() {
    // Clear the console for linux terminal
    printf("\033[H\033[J");
}

void display_memory_usage() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    long total_memory = 0, free_memory = 0, used_memory = 0;

    // Open the meminfo file to read memory stats
    fp = fopen("/proc/meminfo", "r");
    if(fp == NULL) {
        perror("Failed to open meminfo");
        return;
    }
    
    // Read the values for total and free memory from meminfo
    while(fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        if(sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {
            continue;
        }
        if(sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {
            continue;
        }
    }
    
    fclose(fp);

    // Calculate used memory
    used_memory = total_memory - free_memory;

    // Display memory usage statistics
    printf("Memory Usage Monitor:\n");
    printf("=====================\n");
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory:  %ld kB\n", free_memory);
    printf("Used Memory:  %ld kB\n", used_memory);
    
    if (total_memory > 0) {
        // Display percentage of used memory
        printf("Used Memory Percentage: %.2f%%\n\n", (used_memory / (float)total_memory) * 100);
    }
}

int main() {
    while(1) {
        clear_console();
        display_memory_usage();
        
        // Wait for the defined delay before refreshing
        sleep(REPEAT_DELAY);
    }
    
    return 0;
}