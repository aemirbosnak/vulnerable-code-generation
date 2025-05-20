//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MEMINFO_PATH "/proc/meminfo"
#define BUFFER_SIZE 256
#define TIME_INTERVAL 2 // Time interval to update statistics

typedef struct {
    long total;
    long free;
    long available;
    long buffers;
    long cached;
} MemoryStats;

void parse_memory_info(MemoryStats *mem_stats) {
    FILE *fp = fopen(MEMINFO_PATH, "r");
    if (fp == NULL) {
        perror("Unable to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &mem_stats->total) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %ld kB", &mem_stats->free) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemAvailable: %ld kB", &mem_stats->available) == 1) {
            continue;
        }
        if (sscanf(buffer, "Buffers: %ld kB", &mem_stats->buffers) == 1) {
            continue;
        }
        if (sscanf(buffer, "Cached: %ld kB", &mem_stats->cached) == 1) {
            continue;
        }
    }

    fclose(fp);
}

void display_memory_stats(MemoryStats *mem_stats) {
    printf("\n==========================\n");
    printf("Memory Statistics:\n");
    printf("==========================\n");
    printf("Total Memory: %ld kB\n", mem_stats->total);
    printf("Free Memory: %ld kB\n", mem_stats->free);
    printf("Available Memory: %ld kB\n", mem_stats->available);
    printf("Memory Buffers: %ld kB\n", mem_stats->buffers);
    printf("Cached Memory: %ld kB\n", mem_stats->cached);
    printf("==========================\n");
}

void calculate_memory_usage(MemoryStats *mem_stats) {
    long used = mem_stats->total - mem_stats->free;
    long buffer_usage = mem_stats->buffers + mem_stats->cached;
    long actual_used = used - buffer_usage;

    printf("Memory Usage Analysis:\n");
    printf("Used Memory: %ld kB\n", used);
    printf("Actual Used Memory (after cache/buffers): %ld kB\n", actual_used);
    printf("Usage Ratio: %.2f%%\n", (float)actual_used / (float)mem_stats->total * 100);
}

int main() {
    MemoryStats mem_stats;

    while (1) {
        parse_memory_info(&mem_stats);
        display_memory_stats(&mem_stats);
        calculate_memory_usage(&mem_stats);

        printf("Sleeping for %d seconds...\n", TIME_INTERVAL);
        sleep(TIME_INTERVAL);
    }

    return 0;
}