//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MEMINFO_FILE "/proc/meminfo"
#define LINE_SIZE 256

void display_memory_usage() {
    FILE *file = fopen(MEMINFO_FILE, "r");
    if (!file) {
        perror("Failed to open meminfo file");
        exit(EXIT_FAILURE);
    }
    
    char line[LINE_SIZE];
    long total_memory = 0;
    long free_memory = 0;
    long available_memory = 0;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(line, "MemFree: %ld kB", &free_memory) == 1) {
            continue;
        }
        if (sscanf(line, "MemAvailable: %ld kB", &available_memory) == 1) {
            continue;
        }
    }
    
    fclose(file);
    
    long used_memory = total_memory - free_memory;
    long percent_used = (used_memory * 100) / total_memory;

    printf("\n==================== Memory Usage ====================\n");
    printf("Total Memory:   %ld kB\n", total_memory);
    printf("Used Memory:    %ld kB\n", used_memory);
    printf("Free Memory:    %ld kB\n", free_memory);
    printf("Available Memory:%ld kB\n", available_memory);
    printf("Percent Used:   %ld%%\n", percent_used);
    printf("======================================================\n");
}

int main() {
    while (1) {
        display_memory_usage();
        sleep(2);  // Refresh every 2 seconds
    }
    return 0;
}