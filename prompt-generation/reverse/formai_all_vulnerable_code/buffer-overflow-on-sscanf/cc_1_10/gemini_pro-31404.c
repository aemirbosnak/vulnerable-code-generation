//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define KB (1024)
#define MB (1024 * 1024)
#define GB (1024 * 1024 * 1024)

struct ram_usage {
    size_t total;
    size_t used;
    size_t free;
    size_t buffers;
    size_t cached;
};

struct ram_usage get_ram_usage() {
    struct ram_usage usage;
    char buf[256];
    int fd = open("/proc/meminfo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    while (read(fd, buf, sizeof(buf)) > 0) {
        if (sscanf(buf, "MemTotal: %lu kB", &usage.total) == 1) {
            continue;
        }
        if (sscanf(buf, "MemFree: %lu kB", &usage.free) == 1) {
            continue;
        }
        if (sscanf(buf, "Buffers: %lu kB", &usage.buffers) == 1) {
            continue;
        }
        if (sscanf(buf, "Cached: %lu kB", &usage.cached) == 1) {
            continue;
        }
    }
    close(fd);
    usage.used = usage.total - usage.free - usage.buffers - usage.cached;
    return usage;
}

int main() {
    struct ram_usage usage = get_ram_usage();
    printf("Total memory: %lu MB\n", usage.total / MB);
    printf("Used memory: %lu MB\n", usage.used / MB);
    printf("Free memory: %lu MB\n", usage.free / MB);
    printf("Buffers: %lu MB\n", usage.buffers / MB);
    printf("Cached: %lu MB\n", usage.cached / MB);
    return 0;
}