//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define INTERVAL 2  // Time interval for updating the RAM usage
#define BUFFER_SIZE 256

void get_memory_usage(long *total_memory, long *free_memory, long *available_memory) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, fp)) {
        if (sscanf(buffer, "MemTotal: %ld kB", total_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %ld kB", free_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemAvailable: %ld kB", available_memory) == 1) {
            continue;
        }
    }

    fclose(fp);
}

void display_memory_usage(long total_memory, long free_memory, long available_memory) {
    long used_memory = total_memory - free_memory;
    
    printf("\n");
    printf("RAM Usage Monitor\n");
    printf("===================\n");
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Used Memory: %ld kB\n", used_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Available Memory: %ld kB\n", available_memory);
    printf("===================\n");
}

int main() {
    long total_memory, free_memory, available_memory;

    printf("Starting the RAM usage monitor. Press Ctrl+C to exit.\n");

    while (1) {
        get_memory_usage(&total_memory, &free_memory, &available_memory);
        display_memory_usage(total_memory, free_memory, available_memory);
        sleep(INTERVAL);
    }

    return 0;
}