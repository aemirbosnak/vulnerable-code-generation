//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void display_memory_usage() {
    FILE *fp;
    char buffer[256];
    long total_memory = 0;
    long free_memory = 0;
    long used_memory = 0;

    // Opening the meminfo file to read memory stats
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Reading the memory information
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {
            // Got the total memory
        } else if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {
            // Got the free memory
        }
    }
    
    // Calculating used memory
    used_memory = total_memory - free_memory;

    // Displaying the memory usage
    printf("\n================== RAM Usage Monitor ==================\n");
    printf("Total Memory:    %ld kB\n", total_memory);
    printf("Free Memory:     %ld kB\n", free_memory);
    printf("Used Memory:     %ld kB\n", used_memory);
    printf("========================================================\n");
    
    // Close the file
    fclose(fp);

    // Adding a separator for clarity in the console
    for (int i = 0; i < 50; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    printf("Welcome to the Exciting RAM Usage Monitor!\n");
    printf("Starting the monitor... Hold on to your seats!\n");
    
    // Continuous loop to update memory usage every second
    while (1) {
        display_memory_usage();
        sleep(1); // Wait for 1 second
    }

    return 0;
}