//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

// Function to clear the screen for a cleaner output
void clear_screen() {
    printf("\033[H\033[J");
}

// Function to display memory information
void display_memory_info() {
    FILE *fp;
    char buffer[BUFFER_SIZE];

    // Open the meminfo file which contains information about RAM usage
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    clear_screen();
    printf("=== RAM Usage Monitor ===\n\n");

    // Print out relevant memory information
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        if (strncmp(buffer, "MemTotal:", 9) == 0 || 
            strncmp(buffer, "MemFree:", 8) == 0 || 
            strncmp(buffer, "Buffers:", 8) == 0 || 
            strncmp(buffer, "Cached:", 7) == 0 || 
            strncmp(buffer, "SwapTotal:", 10) == 0 ||
            strncmp(buffer, "SwapFree:", 9) == 0) {
            printf("%s", buffer);
        }
    }
    
    fclose(fp);
}

// Function to get total and free memory for a more detailed view
void calculate_memory_usage() {
    long total_memory = 0;
    long free_memory = 0;

    FILE *fp;
    char buffer[BUFFER_SIZE];

    // Open meminfo file again to calculate ratios
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {
            ;
        }
        if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {
            ;
        }
    }
    
    fclose(fp);

    long used_memory = total_memory - free_memory;
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Used Memory: %ld kB\n", used_memory);
    printf("Free Memory: %ld kB\n", free_memory);
}

// Main function to run the RAM monitor
int main() {
    printf("Press CTRL+C to exit.\n");
    
    // Loop to display memory information every second
    while (1) {
        display_memory_info();
        calculate_memory_usage();
        sleep(1); // update every second
    }

    return 0;
}