//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to read RAM usage from /proc/meminfo
void check_ram_usage() {
    FILE *file;
    char buffer[256];
    long total_memory = 0;
    long free_memory = 0;
    
    // The detective's notebook: records our findings.
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Alas! The notebook is missing, unable to find /proc/meminfo");
        return;
    }

    // Read total and free memory values
    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {
            // Total memory found
        } else if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {
            // Free memory found
        }
    }
    fclose(file);

    // Deductions made: calculating used memory
    long used_memory = total_memory - free_memory;

    // Report findings
    printf("Sherlock's RAM Usage Report:\n");
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Used Memory: %ld kB\n", used_memory);
    printf("-------------------------------------------------\n");
}

int main() {
    printf("The game is afoot! Monitoring RAM usage:\n");
    
    while (1) {
        // Check the RAM usage at intervals, akin to Holmes observing his surroundings
        check_ram_usage();
        sleep(5); // A brief pause, ensuring we do not overwhelm our senses
    }

    return 0;
}