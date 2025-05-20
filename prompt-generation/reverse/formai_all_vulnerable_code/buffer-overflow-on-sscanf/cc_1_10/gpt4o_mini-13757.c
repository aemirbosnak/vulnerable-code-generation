//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER 256

void display_memory_usage() {
    FILE *fp;
    char buffer[MAX_BUFFER];
    unsigned long total_memory = 0;
    unsigned long free_memory = 0;
    unsigned long available_memory = 0;
    unsigned long used_memory = 0;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read memory information line by line
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (sscanf(buffer, "MemTotal: %lu kB", &total_memory) == 1) {
            // total_memory captured
        }
        if (sscanf(buffer, "MemFree: %lu kB", &free_memory) == 1) {
            // free_memory captured
        }
        if (sscanf(buffer, "MemAvailable: %lu kB", &available_memory) == 1) {
            // available_memory captured
        }
    }
    fclose(fp);

    used_memory = total_memory - free_memory;

    // Display memory usage
    printf("\n====================== Memory Usage ======================");
    printf("\nTotal Memory: \t\t%lu kB", total_memory);
    printf("\nFree Memory: \t\t%lu kB", free_memory);
    printf("\nAvailable Memory: \t%lu kB", available_memory);
    printf("\nUsed Memory: \t\t%lu kB", used_memory);
    printf("\n==========================================================\n");
}

int main() {
    char command;
    
    printf("RAM Usage Monitor\n");
    printf("Press 'q' to quit.\n");

    // Main loop to display memory usage continuously
    while (1) {
        display_memory_usage();
        
        // Check for user input to exit
        if (getchar() == 'q') {
            printf("Exiting RAM Usage Monitor...\n");
            break;
        }

        // Introduce delay for next update
        sleep(2);
    }
    
    return 0;
}