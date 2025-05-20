//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MEGABYTE (1024*1024)

int main() {
    int fd;
    void *addr;
    struct stat sb;
    int pagesize = sysconf(_SC_PAGESIZE);
    unsigned long total_ram = 0;
    unsigned long free_ram = 0;
    unsigned long used_ram = 0;

    fd = open("/proc/meminfo", O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening /proc/meminfo\n");
        exit(1);
    }

    if (fstat(fd, &sb) == -1) {
        fprintf(stderr, "Error getting file status\n");
        exit(1);
    }

    addr = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        fprintf(stderr, "Error mapping file\n");
        exit(1);
    }

    char *meminfo = addr;

    while (*meminfo!= '\0') {
        if (sscanf(meminfo, "MemTotal: %lu kB", &total_ram) == 1) {
            total_ram *= 1024;
        } else if (sscanf(meminfo, "MemFree: %lu kB", &free_ram) == 1) {
            free_ram *= 1024;
        } else if (sscanf(meminfo, "Buffers: %lu kB", &used_ram) == 1) {
            used_ram *= 1024;
        }

        meminfo += strlen(meminfo) + 1;
    }

    munmap(addr, sb.st_size);
    close(fd);

    printf("Total RAM: %lu MB\n", total_ram / MEGABYTE);
    printf("Free RAM: %lu MB\n", free_ram / MEGABYTE);
    printf("Used RAM: %lu MB\n", (total_ram - free_ram) / MEGABYTE);

    return 0;
}