//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
#define RAM_INFO_PATH "/proc/meminfo"

void get_ram_usage(long *total, long *free, long *available) {
    FILE *file = fopen(RAM_INFO_PATH, "r");
    if (!file) {
        perror("Failed to open meminfo");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];

    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "MemTotal: %ld kB", total) == 1) continue;
        if (sscanf(buffer, "MemFree: %ld kB", free) == 1) continue;
        if (sscanf(buffer, "MemAvailable: %ld kB", available) == 1) continue;
    }

    fclose(file);
}

void display_ram_usage(long total, long free, long available) {
    long used = total - free;

    printf("\nRAM Usage Statistics:\n");
    printf("======================\n");
    printf("Total Memory:     %ld kB\n", total);
    printf("Free Memory:      %ld kB\n", free);
    printf("Available Memory: %ld kB\n", available);
    printf("Used Memory:      %ld kB (%.2f%%)\n", used, (used / (float)total) * 100);
}

int main() {
    long total_memory = 0;
    long free_memory = 0;
    long available_memory = 0;

    printf("RAM Usage Monitor - Press Ctrl+C to exit\n");

    while (1) {
        get_ram_usage(&total_memory, &free_memory, &available_memory);
        display_ram_usage(total_memory, free_memory, available_memory);
        
        sleep(2); // wait for 2 seconds before refreshing
    }

    return 0;
}