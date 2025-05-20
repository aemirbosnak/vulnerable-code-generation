//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void display_memory_info() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    unsigned long total_memory = 0, free_memory = 0, available_memory = 0, buffers = 0, cached = 0;

    // Open the /proc/meminfo file to read memory stats
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Reading memory information from the file
    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "MemTotal: %lu kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %lu kB", &free_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemAvailable: %lu kB", &available_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "Buffers: %lu kB", &buffers) == 1) {
            continue;
        }
        if (sscanf(buffer, "Cached: %lu kB", &cached) == 1) {
            continue;
        }
    }
    fclose(file);

    // Calculate used memory
    unsigned long used_memory = total_memory - free_memory;

    // Display memory information
    printf("\nMemory Usage Information:\n");
    printf("----------------------------\n");
    printf("Total Memory:      %lu kB\n", total_memory);
    printf("Free Memory:       %lu kB\n", free_memory);
    printf("Used Memory:       %lu kB\n", used_memory);
    printf("Available Memory:  %lu kB\n", available_memory);
    printf("Buffers:           %lu kB\n", buffers);
    printf("Cached:            %lu kB\n", cached);
    printf("----------------------------\n");
    printf("Used Percentage:   %.2f%%\n", (double)used_memory / total_memory * 100);
    printf("----------------------------\n");
}

int main() {
    char input;

    printf("RAM Usage Monitor\n");
    printf("----------------------------\n");

    // Continuously monitor memory usage until the user wants to exit
    while (1) {
        display_memory_info();
        printf("\nPress 'q' to exit or any other key to refresh: ");
        input = getchar();
        while (getchar() != '\n'); // Clear the input buffer
        if (input == 'q') {
            break;
        }
        sleep(2); // Refresh every 2 seconds
    }

    printf("Exiting RAM Usage Monitor...\n");
    return 0;
}