//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_MEMORY_INFO 256

typedef struct {
    long total;
    long free;
    long used;
    long shared;
    long buff_cache;
} MemoryInfo;

void parse_memory_info(MemoryInfo *mem_info) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[MAX_MEMORY_INFO];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %ld kB", &mem_info->total) == 1) continue;
        if (sscanf(line, "MemFree: %ld kB", &mem_info->free) == 1) continue;
        if (sscanf(line, "Shmem: %ld kB", &mem_info->shared) == 1) continue;
        if (sscanf(line, "Buffers: %ld kB", &mem_info->buff_cache) == 1) continue;
    }

    fclose(fp);
    
    mem_info->used = mem_info->total - mem_info->free;
}

void display_memory_usage(MemoryInfo mem_info) {
    printf("Memory Usage Information:\n");
    printf("Total Memory: %ld kB\n", mem_info.total);
    printf("Used Memory: %ld kB\n", mem_info.used);
    printf("Free Memory: %ld kB\n", mem_info.free);
    printf("Shared Memory: %ld kB\n", mem_info.shared);
    printf("Buffers/Cache: %ld kB\n", mem_info.buff_cache);
    printf("\n");

    // Calculate percentage usage
    double memory_usage_percentage = ((double)mem_info.used / (double)mem_info.total) * 100;
    printf("Memory Usage: %.2f%%\n", memory_usage_percentage);
}

int main() {
    MemoryInfo mem_info;

    while (1) {
        parse_memory_info(&mem_info);
        display_memory_usage(mem_info);
        
        // Sleep for a while to reduce the speed of updates
        sleep(5);
    }

    return 0;
}