//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void clear_screen() {
    // ANSI escape code for clearing the screen
    printf("\033[H\033[J");
}

void display_memory_usage() {
    // Reading memory stats from /proc/meminfo
    FILE *fp = fopen("/proc/meminfo", "r");
    char line[256];
    if (fp == NULL) {
        perror("Failed to read memory info");
        return;
    }

    // Variables for total and free memory
    unsigned long total_memory = 0, free_memory = 0;

    // Parse the lines to extract total and free memory values
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %lu kB", &total_memory) == 1) {
            // Total memory found
        } else if (sscanf(line, "MemFree: %lu kB", &free_memory) == 1) {
            // Free memory found
            break; // No need to read further
        }
    }
    fclose(fp);

    // Calculate used memory
    unsigned long used_memory = total_memory - free_memory;

    // Display the memory usage
    printf("=====================================\n");
    printf("Total Memory:     %lu kB\n", total_memory);
    printf("Free Memory:      %lu kB\n", free_memory);
    printf("Used Memory:      %lu kB\n", used_memory);
    printf("=====================================\n");
}

void spin_animation(int duration) {
    // A simple spinning animation during the monitor's operation
    char spin_chars[] = {'|', '/', '-', '\\'};
    int spin_count = 0;
    for (int i = 0; i < duration; ++i) {
        printf("\rChecking memory usage... %c ", spin_chars[spin_count % 4]);
        fflush(stdout);
        usleep(250000); // Sleep for a quarter of a second
        spin_count++;
    }
    printf("\r                      \n"); // Clear the line
}

// Main function to monitor RAM usage with a vibrant flair
int main() {
    clear_screen();
    printf("******************************************\n");
    printf("* Welcome to the Mind-Bending RAM Monitor *\n");
    printf("******************************************\n");

    while (1) {
        display_memory_usage();
        
        // Perform spin animation while fetching the memory updates
        spin_animation(5);

        // Sleep for 2 seconds before the next update
        printf("Gathering data again in 2 seconds...\n");
        sleep(2);
    }

    return 0;
}