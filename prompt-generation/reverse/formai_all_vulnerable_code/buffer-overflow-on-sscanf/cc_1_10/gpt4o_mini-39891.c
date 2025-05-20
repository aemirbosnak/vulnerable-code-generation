//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
#define SLEEP_INTERVAL 2

void clear_screen() {
    printf("\033[H\033[J");  // ANSI escape code to clear the screen
}

void display_memory_usage() {
    FILE *file;
    char buffer[BUFFER_SIZE];

    unsigned long total_memory = 0;
    unsigned long free_memory = 0;
    unsigned long used_memory = 0;

    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open meminfo");
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        if (sscanf(buffer, "MemTotal: %lu kB", &total_memory) == 1) {
            // total memory found
        } else if (sscanf(buffer, "MemFree: %lu kB", &free_memory) == 1) {
            // free memory found
        }
    }
    fclose(file);

    used_memory = total_memory - free_memory;

    // Displaying results
    clear_screen();
    printf("=== RAM Usage Monitor ===\n\n");
    printf("Total Memory: \033[1;32m%lu kB\033[0m\n", total_memory);
    printf("Free Memory: \033[1;34m%lu kB\033[0m\n", free_memory);
    printf("Used Memory: \033[1;31m%lu kB\033[0m\n", used_memory);
    printf("\nMemory Usage Percentage: \033[1;33m%.2f%%\033[0m\n",
           (double)used_memory / total_memory * 100);
}

int main() {
    while (1) {
        display_memory_usage();
        sleep(SLEEP_INTERVAL);
    }
    return 0;
}