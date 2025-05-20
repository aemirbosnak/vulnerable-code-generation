//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void clear_screen() {
    // Function to clear the terminal screen
    printf("\033[H\033[J");
}

void display_memory_usage() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    long total_memory = 0;
    long free_memory = 0;
    long available_memory = 0;
    long buffers_memory = 0;
    long cached_memory = 0;

    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open /proc/meminfo\n");
        exit(EXIT_FAILURE);
    }

    // Read the memory info from the file
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemAvailable: %ld kB", &available_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "Buffers: %ld kB", &buffers_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "Cached: %ld kB", &cached_memory) == 1) {
            continue;
        }
    }
    fclose(file);

    // Calculate used memory
    long used_memory = total_memory - free_memory;

    // Display the memory usage
    clear_screen();
    printf("=== RAM Usage Monitor ===\n");
    printf("Total Memory:       %ld kB\n", total_memory);
    printf("Free Memory:        %ld kB\n", free_memory);
    printf("Available Memory:    %ld kB\n", available_memory);
    printf("Used Memory:        %ld kB\n", used_memory);
    printf("Buffers Memory:     %ld kB\n", buffers_memory);
    printf("Cached Memory:      %ld kB\n", cached_memory);
    printf("========================\n");
}

int main() {
    printf("Welcome to RAM Usage Monitor!\n");
    printf("Press CTRL+C to exit.\n");

    while (1) {
        display_memory_usage();
        sleep(2); // Updates every 2 seconds
    }

    return 0;
}