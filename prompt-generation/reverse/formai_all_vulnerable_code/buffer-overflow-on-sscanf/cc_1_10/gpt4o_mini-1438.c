//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MEMORY_INFO_FILE "/proc/meminfo"

void parse_memory_info(char *line, long *total_memory, long *free_memory) {
    if (sscanf(line, "MemTotal: %ld kB", total_memory) == 1) {
        // Total memory found
    } else if (sscanf(line, "MemFree: %ld kB", free_memory) == 1) {
        // Free memory found
    }
}

void get_memory_usage(long *total_memory, long *free_memory, double *used_memory_percentage) {
    FILE *fp = fopen(MEMORY_INFO_FILE, "r");
    if (fp == NULL) {
        perror("Failed to open memory info file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    *total_memory = 0;
    *free_memory = 0;

    while (fgets(line, sizeof(line), fp)) {
        parse_memory_info(line, total_memory, free_memory);
    }
    fclose(fp);

    long used_memory = *total_memory - *free_memory;
    *used_memory_percentage = ((double)used_memory / (double)*total_memory) * 100.0;
}

void display_memory_usage(long total_memory, long free_memory, double used_memory_percentage) {
    system("clear");
    printf("Memory Usage Monitor\n");
    printf("---------------------\n");
    printf("Total Memory:    %ld kB\n", total_memory);
    printf("Free Memory:     %ld kB\n", free_memory);
    printf("Used Memory:     %.2f%%\n", used_memory_percentage);
    printf("---------------------\n");
}

void monitor_memory_usage() {
    long total_memory;
    long free_memory;
    double used_memory_percentage;

    while (1) {
        get_memory_usage(&total_memory, &free_memory, &used_memory_percentage);
        display_memory_usage(total_memory, free_memory, used_memory_percentage);
        sleep(1);  // Refresh every second
    }
}

int main() {
    printf("Starting Memory Usage Monitor...\n");
    printf("Press Ctrl+C to stop.\n");
    monitor_memory_usage();
    return 0;
}