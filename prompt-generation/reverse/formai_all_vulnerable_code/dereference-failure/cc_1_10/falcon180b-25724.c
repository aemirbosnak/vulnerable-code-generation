//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096
#define NUM_PAGES 10

#define MAP_FILE_NAME "mapped_file"

void *map_file(const char *filename, size_t size) {
    int fd = open(filename, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        fprintf(stderr, "Failed to open file %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        fprintf(stderr, "Failed to map file %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    if (ftruncate(fd, size) == -1) {
        fprintf(stderr, "Failed to truncate file %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    close(fd);
    return addr;
}

int main() {
    void *addr = map_file(MAP_FILE_NAME, NUM_PAGES * PAGE_SIZE);
    if (addr == MAP_FAILED) {
        return 1;
    }

    printf("Mapped file %s at address %p\n", MAP_FILE_NAME, addr);

    for (int i = 0; i < NUM_PAGES; i++) {
        char *page_addr = (char *)addr + i * PAGE_SIZE;
        printf("Page %d mapped at address %p\n", i, page_addr);
    }

    munmap(addr, NUM_PAGES * PAGE_SIZE);
    return 0;
}