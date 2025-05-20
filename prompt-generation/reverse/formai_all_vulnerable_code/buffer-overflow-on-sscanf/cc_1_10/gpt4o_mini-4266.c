//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256

void clear_screen() {
    // Clear the terminal screen with ANSI escape codes
    printf("\033[H\033[J");
}

void display_memory_usage() {
    char buffer[BUFFER_SIZE];
    FILE *meminfo = fopen("/proc/meminfo", "r");

    if (meminfo == NULL) {
        fprintf(stderr, "Error: Could not open /proc/meminfo\n");
        return;
    }

    unsigned long total_memory = 0;
    unsigned long free_memory = 0;

    while (fgets(buffer, BUFFER_SIZE, meminfo) != NULL) {
        if (sscanf(buffer, "MemTotal: %lu kB", &total_memory) == 1) {
            // Successfully retrieved total memory
        }
        if (sscanf(buffer, "MemFree: %lu kB", &free_memory) == 1) {
            // Successfully retrieved free memory
        }
    }

    fclose(meminfo);

    unsigned long used_memory = total_memory - free_memory;
    unsigned int percent_used = (used_memory * 100) / total_memory;

    // Display the results energetically!
    printf("\n 🎉 Memory Usage Monitor 🎉\n");
    printf("=================================\n");
    printf(" Total Memory:     %lu kB\n", total_memory);
    printf(" Free Memory:      %lu kB\n", free_memory);
    printf(" Used Memory:      %lu kB\n", used_memory);
    printf(" Percentage Used:  %u%%\n", percent_used);
    printf("=================================\n");
}

int main() {
    printf("🌟 Welcome to the RAM Usage Monitor! 🌟\n");
    printf("🏁 Press Ctrl+C to stop monitoring.\n");

    while (1) {
        clear_screen();
        display_memory_usage();
        sleep(2);  // Refresh every 2 seconds
    }

    return 0;
}