//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define KB (1024)
#define MB (1024 * KB)
#define GB (1024 * MB)

int main() {
    int fd;
    uint64_t total_mem, free_mem;

    // Open the /proc/meminfo file
    fd = open("/proc/meminfo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Read the MemTotal and MemFree fields
    char line[1024];
    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("lseek");
        close(fd);
        return EXIT_FAILURE;
    }
    if (read(fd, line, sizeof(line)) == -1) {
        perror("read");
        close(fd);
        return EXIT_FAILURE;
    }

    uint64_t memtotal, memfree;
    if (sscanf(line, "MemTotal: %llu kB", &memtotal) != 1) {
        fprintf(stderr, "Error parsing MemTotal\n");
        close(fd);
        return EXIT_FAILURE;
    }
    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("lseek");
        close(fd);
        return EXIT_FAILURE;
    }
    if (read(fd, line, sizeof(line)) == -1) {
        perror("read");
        close(fd);
        return EXIT_FAILURE;
    }
    if (sscanf(line, "MemFree: %llu kB", &memfree) != 1) {
        fprintf(stderr, "Error parsing MemFree\n");
        close(fd);
        return EXIT_FAILURE;
    }

    // Calculate the total and free memory in MB
    total_mem = memtotal / KB;
    free_mem = memfree / KB;

    // Print the results
    printf("Total RAM: %llu MB\n", total_mem);
    printf("Free RAM: %llu MB\n", free_mem);
    printf("Used RAM: %llu MB\n", total_mem - free_mem);

    // Close the file
    close(fd);

    return EXIT_SUCCESS;
}