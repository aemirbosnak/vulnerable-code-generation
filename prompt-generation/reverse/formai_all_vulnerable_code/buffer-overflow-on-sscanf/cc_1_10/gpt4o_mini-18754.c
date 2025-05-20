//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define SLEEP_DURATION 5

typedef struct {
    long total_memory;
    long free_memory;
    long available_memory;
    long cached_memory;
    long buffers_memory;
} MemoryInfo;

void parse_memory_info(MemoryInfo *mem_info) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Unable to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (sscanf(buffer, "MemTotal: %ld kB", &mem_info->total_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %ld kB", &mem_info->free_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemAvailable: %ld kB", &mem_info->available_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "Cached: %ld kB", &mem_info->cached_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "Buffers: %ld kB", &mem_info->buffers_memory) == 1) {
            continue;
        }
    }
    fclose(fp);
}

void display_memory_usage(const MemoryInfo *mem_info) {
    long used_memory = mem_info->total_memory - mem_info->free_memory;

    printf("\nMemory Usage Information:\n");
    printf("Total Memory: %ld kB\n", mem_info->total_memory);
    printf("Free Memory: %ld kB\n", mem_info->free_memory);
    printf("Available Memory: %ld kB\n", mem_info->available_memory);
    printf("Used Memory: %ld kB\n", used_memory);
    printf("Cached Memory: %ld kB\n", mem_info->cached_memory);
    printf("Buffers Memory: %ld kB\n", mem_info->buffers_memory);
    printf("------------------------------------------------------\n");
}

int main() {
    MemoryInfo mem_info;

    while (1) {
        parse_memory_info(&mem_info);
        display_memory_usage(&mem_info);
        sleep(SLEEP_DURATION);
    }
    
    return 0;
}