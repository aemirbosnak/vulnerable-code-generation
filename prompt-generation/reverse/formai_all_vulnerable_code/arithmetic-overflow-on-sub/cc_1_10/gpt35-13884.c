//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

struct MemUsage {
    unsigned long mem_total;
    unsigned long mem_used;
};

int getMemUsage(struct MemUsage *mem) {
    FILE *fd;
    char line[256];
    unsigned long mem_total, mem_free, mem_buffers, mem_cached;
    unsigned long mem_used, buffers, cached;

    fd = fopen("/proc/meminfo", "r");
    if (fd == NULL) return -1;

    fgets(line, sizeof(line), fd);
    sscanf(line, "MemTotal: %lu kB", &mem_total);
    fgets(line, sizeof(line), fd);
    sscanf(line, "MemFree: %lu kB", &mem_free);
    fgets(line, sizeof(line), fd);
    sscanf(line, "Buffers: %lu kB", &mem_buffers);
    fgets(line, sizeof(line), fd);
    sscanf(line, "Cached: %lu kB", &mem_cached);

    fclose(fd);

    mem_used = mem_total - mem_free;
    buffers = mem_used + mem_buffers - mem_cached;
    cached = mem_used - buffers;
    
    mem->mem_total = mem_total;
    mem->mem_used = mem_used;

    return 0;
}

void printHeader() {
    printf("*******************************************************************\n");
    printf("*                 C RAM Usage Monitor Example                      *\n");
    printf("*******************************************************************\n");
    printf("* Press Ctrl+C to exit                                             *\n");
    printf("*                                                                   *\n");
    printf("* This program displays the current RAM usage of your system.      *\n");
    printf("* The program updates the RAM usage every second.                  *\n");
    printf("*******************************************************************\n");
}

void printUsage(struct MemUsage *mem) {
    printf("\r>> RAM Usage: %.2f%% (%lu/%lu MB)", 
           (double)mem->mem_used / mem->mem_total * 100,
           mem->mem_used / 1024 / 1024, 
           mem->mem_total / 1024 / 1024);
    fflush(stdout);
}

int main(int argc, char **argv) {
    struct MemUsage mem;
    time_t start, end, diff;

    printHeader();

    while (1) {
        start = time(NULL);
        getMemUsage(&mem);
        printUsage(&mem);
        end = time(NULL);
        diff = end - start;
        sleep(1 - diff);
    }

    return 0;
}