//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define FILE_PATH "/proc/meminfo"

void read_memory_info(long *total_memory, long *free_memory, long *available_memory) {
    FILE *fp = fopen(FILE_PATH, "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %ld kB", total_memory) == 1)
            continue;
        if (sscanf(line, "MemFree: %ld kB", free_memory) == 1)
            continue;
        if (sscanf(line, "MemAvailable: %ld kB", available_memory) == 1)
            continue;
    }

    fclose(fp);
}

void print_memory_usage(long total, long free, long available) {
    long used = total - free;
    long percentage_used = (100 * used) / total;

    printf("Total Memory: %ld kB\n", total);
    printf("Free Memory: %ld kB\n", free);
    printf("Available Memory: %ld kB\n", available);
    printf("Used Memory: %ld kB (%.2f%%)\n", used, (float)percentage_used);
}

void display_memory_info() {
    long total_memory = 0, free_memory = 0, available_memory = 0;
    read_memory_info(&total_memory, &free_memory, &available_memory);
    print_memory_usage(total_memory, free_memory, available_memory);
}

void continuously_monitor_memory_usage(int interval) {
    while (1) {
        display_memory_info();
        sleep(interval);
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int interval = 5; // Default interval

    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "Interval must be a positive integer.\n");
            return EXIT_FAILURE;
        }
    }

    printf("Starting RAM usage monitor (refresh every %d seconds)...\n", interval);
    continuously_monitor_memory_usage(interval);

    return EXIT_SUCCESS;
}