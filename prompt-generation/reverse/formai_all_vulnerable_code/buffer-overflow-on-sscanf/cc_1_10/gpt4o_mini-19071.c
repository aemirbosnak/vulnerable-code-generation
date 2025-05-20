//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void print_memory_usage() {
    FILE *meminfo;
    char buffer[BUFFER_SIZE];
    size_t total_memory = 0;
    size_t free_memory = 0;
    size_t available_memory = 0;
    
    meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, meminfo)) {
        if (sscanf(buffer, "MemTotal: %zu kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %zu kB", &free_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemAvailable: %zu kB", &available_memory) == 1) {
            continue;
        }
    }

    fclose(meminfo);

    printf("Total Memory: %zu kB\n", total_memory);
    printf("Free Memory: %zu kB\n", free_memory);
    printf("Available Memory: %zu kB\n", available_memory);
    printf("Used Memory: %zu kB\n", total_memory - free_memory);
    printf("\nMemory Usage Percentage: %.2f%%\n",
           ((double)(total_memory - free_memory) / (double)total_memory) * 100);
}

int main() {
    printf("Welcome to the RAM Usage Monitor!\n");
    printf("Monitoring your system's RAM usage...\n");

    while (1) {
        print_memory_usage();
        printf("\n");
        sleep(5); // Update every 5 seconds
    }

    return 0;
}