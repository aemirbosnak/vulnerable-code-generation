//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to get the total and free RAM from /proc/meminfo
void get_memory_info(long *total_ram, long *free_ram) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[256];
    
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", total_ram) == 1) {
            *total_ram /= 1024;  // Convert to MB
        } else if (sscanf(line, "MemFree: %ld kB", free_ram) == 1) {
            *free_ram /= 1024;  // Convert to MB
        }

        if (*total_ram && *free_ram) break; // We found both values
    }
    
    fclose(file);
}

// Function to print memory usage
void print_memory_usage(long total_ram, long free_ram) {
    long used_ram = total_ram - free_ram;
    
    printf("Total RAM: %ld MB\n", total_ram);
    printf("Free RAM:  %ld MB\n", free_ram);
    printf("Used RAM:  %ld MB\n", used_ram);
    
    float usage_percentage = ((float)used_ram / (float)total_ram) * 100;
    printf("RAM Usage: %.2f%%\n", usage_percentage);
}

// Main function to monitor RAM usage at regular intervals
int main() {
    long total_ram = 0;
    long free_ram = 0;
    int interval = 5; // Refresh interval in seconds

    printf("Starting RAM usage monitor...\n");
    
    while (1) {
        get_memory_info(&total_ram, &free_ram);
        print_memory_usage(total_ram, free_ram);
        
        printf("Refreshing in %d seconds...\n", interval);
        sleep(interval);
    }

    return 0;
}