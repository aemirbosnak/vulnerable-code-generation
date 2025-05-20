#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    unsigned long total;
    unsigned long free;
    unsigned long available;
    unsigned long buffers;
    unsigned long cached;
} MemoryInfo;

int parse_meminfo(MemoryInfo *info) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) return -1;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %lu kB", &info->total) == 1 ||
            sscanf(line, "MemFree: %lu kB", &info->free) == 1 ||
            sscanf(line, "MemAvailable: %lu kB", &info->available) == 1 ||
            sscanf(line, "Buffers: %lu kB", &info->buffers) == 1 ||
            sscanf(line, "Cached: %lu kB", &info->cached) == 1) {
            continue;
        }
    }

    fclose(fp);
    return 0;
}

int main() {
    MemoryInfo info;
    if (parse_meminfo(&info) != 0) {
        fprintf(stderr, "Failed to parse /proc/meminfo\n");
        return EXIT_FAILURE;
    }

    printf("Memory Info:\n");
    printf("Total: %lu kB\n", info.total);
    printf("Free: %lu kB\n", info.free);
    printf("Available: %lu kB\n", info.available);
    printf("Buffers: %lu kB\n", info.buffers);
    printf("Cached: %lu kB\n", info.cached);

    return EXIT_SUCCESS;
}
