//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINE_LENGTH 256

typedef struct {
    long total;
    long used;
    long free;
    float used_percentage;
} MemoryStats;

MemoryStats parse_meminfo() {
    MemoryStats mem_stats = {0, 0, 0, 0.0};
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Unable to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", &mem_stats.total) == 1) {
            continue;
        }
        if (sscanf(line, "MemFree: %ld kB", &mem_stats.free) == 1) {
            continue;
        }
        if (sscanf(line, "Buffers: %ld kB", &mem_stats.used) == 1 || 
            sscanf(line, "Cached: %ld kB", &mem_stats.used) == 1) {
            mem_stats.used += mem_stats.used;
        }
    }
    fclose(file);
    
    // Calculate used memory
    mem_stats.used = mem_stats.total - mem_stats.free - mem_stats.used;
    // Calculate used percentage
    mem_stats.used_percentage = (float) mem_stats.used / mem_stats.total * 100.0;

    return mem_stats;
}

void display_memory_stats(MemoryStats mem_stats) {
    system("clear");
    printf("Memory Usage Statistics\n");
    printf("-------------------------------------------------\n");
    printf("Total Memory:     %ld kB\n", mem_stats.total);
    printf("Used Memory:      %ld kB (%.2f%%)\n", mem_stats.used, mem_stats.used_percentage);
    printf("Free Memory:      %ld kB\n", mem_stats.free);
    printf("-------------------------------------------------\n");
}

int main() {
    while (1) {
        MemoryStats mem_stats = parse_meminfo();
        display_memory_stats(mem_stats);
        sleep(1); // update every second
    }
    return 0;
}