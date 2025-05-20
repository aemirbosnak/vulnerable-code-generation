//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILE_PATH "/proc/meminfo"

void parse_memory_info(long *total_memory, long *free_memory, long *available_memory) {
    FILE *fp = fopen(FILE_PATH, "r");
    if (fp == NULL) {
        perror("Failed to open memory info file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %ld kB", total_memory) == 1) {
            continue;
        }
        if (sscanf(line, "MemFree: %ld kB", free_memory) == 1) {
            continue;
        }
        if (sscanf(line, "MemAvailable: %ld kB", available_memory) == 1) {
            continue;
        }
    }

    fclose(fp);
}

void display_statistics(long total_memory, long free_memory, long available_memory) {
    long used_memory = total_memory - free_memory;

    printf("\n==================== RAM Usage Statistics ====================\n");
    printf("Total Memory: \t\t%ld kB\n", total_memory);
    printf("Free Memory: \t\t%ld kB\n", free_memory);
    printf("Available Memory: \t%ld kB\n", available_memory);
    printf("Used Memory: \t\t%ld kB\n", used_memory);
    printf("--------------------------------------------------------------\n");

    printf("Memory Usage Percentage: %.2f%%\n", (double)used_memory / total_memory * 100);
    printf("Free Memory Percentage: %.2f%%\n", (double)free_memory / total_memory * 100);
    printf("Available Memory Percentage: %.2f%%\n", (double)available_memory / total_memory * 100);

    printf("\n==============================================================\n");
}

void memory_monitor(int interval) {
    while (1) {
        long total_memory = 0, free_memory = 0, available_memory = 0;
        parse_memory_info(&total_memory, &free_memory, &available_memory);
        display_statistics(total_memory, free_memory, available_memory);
        sleep(interval);
    }
}

int main() {
    int interval = 5; // Monitor every 5 seconds
    printf("Starting RAM Usage Monitor... (Press Ctrl+C to stop)\n\n");
    
    memory_monitor(interval);

    return 0;
}