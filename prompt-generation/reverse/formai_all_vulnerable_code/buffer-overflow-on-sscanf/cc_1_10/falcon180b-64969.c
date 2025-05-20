//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <fcntl.h>

#define MEGABYTE (1024*1024)
#define GIGABYTE (MEGABYTE*1024)

struct memory_info {
    long long total;
    long long free;
    long long used;
};

int main(int argc, char *argv[])
{
    struct memory_info mem_info;
    char *path = "/proc/meminfo";
    FILE *fp;
    char line[1024];
    int count = 0;

    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error: %s\n", path);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count == 0) {
            sscanf(line, "MemTotal: %lld kB", &mem_info.total);
        } else if (count == 1) {
            sscanf(line, "MemFree: %lld kB", &mem_info.free);
        } else if (count == 2) {
            sscanf(line, "MemAvailable: %lld kB", &mem_info.free);
        } else if (count == 3) {
            sscanf(line, "Buffers: %lld kB", &mem_info.free);
        } else if (count == 4) {
            sscanf(line, "Cached: %lld kB", &mem_info.free);
        }
        count++;
    }

    mem_info.used = mem_info.total - mem_info.free;
    mem_info.free = mem_info.free / MEGABYTE;
    mem_info.used = mem_info.used / MEGABYTE;
    mem_info.total = mem_info.total / MEGABYTE;

    printf("Total RAM: %lld MB\n", mem_info.total);
    printf("Free RAM: %lld MB\n", mem_info.free);
    printf("Used RAM: %lld MB\n", mem_info.used);

    fclose(fp);
    return 0;
}