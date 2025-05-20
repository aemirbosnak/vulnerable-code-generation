//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MEMINFO_PATH "/proc/meminfo"

typedef struct {
    unsigned long total_mem;
    unsigned long free_mem;
    unsigned long buffers;
    unsigned long cached_mem;
} mem_info;

void read_mem_info(mem_info * info) {
    FILE * fp;
    char line[256];
    unsigned long value;

    info->total_mem = 0;
    info->free_mem = 0;
    info->buffers = 0;
    info->cached_mem = 0;

    fp = fopen(MEMINFO_PATH, "r");
    if (fp == NULL)
        return;

    while(fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %lu kB", &value) == 1)
            info->total_mem = value * 1024;
        else if (sscanf(line, "MemFree: %lu kB", &value) == 1)
            info->free_mem = value * 1024;
        else if (sscanf(line, "Buffers: %lu kB", &value) == 1)
            info->buffers = value * 1024;
        else if (sscanf(line, "Cached: %lu kB", &value) == 1)
            info->cached_mem = value * 1024;
    }

    fclose(fp);
}

int main(int argc, char * argv[]) {
    mem_info mem1, mem2;
    unsigned long used_mem;

    while (1) {
        read_mem_info(&mem1);
        sleep(1);
        read_mem_info(&mem2);

        used_mem = mem1.total_mem - mem2.free_mem - mem2.buffers - mem2.cached_mem;

        printf("Used memory: %.2lf MB\n", used_mem / (1024.0 * 1024.0));
    }
    return 0;
}