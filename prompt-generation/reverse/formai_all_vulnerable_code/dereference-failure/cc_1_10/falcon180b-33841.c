//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define PAGE_SIZE (4 * 1024)

typedef struct {
    size_t total;
    size_t used;
    size_t free;
    size_t max;
} MemoryStats;

int get_memory_stats(MemoryStats *stats) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open /proc/meminfo\n");
        return -1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line, "MemTotal: %*s %zu kB", &stats->total);
        } else if (strncmp(line, "MemFree:", 8) == 0) {
            sscanf(line, "MemFree: %*s %zu kB", &stats->free);
        } else if (strncmp(line, "MemAvailable:", 13) == 0) {
            sscanf(line, "MemAvailable: %*s %zu kB", &stats->max);
        }
    }

    fclose(fp);

    stats->used = stats->total - stats->free;

    return 0;
}

int monitor_memory_usage(size_t interval) {
    MemoryStats stats;
    while (true) {
        get_memory_stats(&stats);
        printf("Total: %zu KB, Used: %zu KB, Free: %zu KB, Available: %zu KB\n",
               stats.total, stats.used, stats.free, stats.max);
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <interval_seconds>\n", argv[0]);
        return 1;
    }

    int interval = atoi(argv[1]);
    if (interval <= 0) {
        fprintf(stderr, "Error: Invalid interval\n");
        return 1;
    }

    monitor_memory_usage(interval);

    return 0;
}