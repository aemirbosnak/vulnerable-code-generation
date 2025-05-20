//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

#define PAGE_SIZE 4096
#define NUM_PAGES 1000
#define FILENAME "test.bin"

int main() {
    int fd, i, j;
    char *mem;
    struct timespec start, end;
    double elapsed;

    fd = open(FILENAME, O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    mem = mmap(NULL, PAGE_SIZE * NUM_PAGES, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mem == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    for (i = 0; i < NUM_PAGES; i++) {
        for (j = 0; j < PAGE_SIZE; j++) {
            mem[i * PAGE_SIZE + j] = i % 256;
        }
    }

    clock_gettime(CLOCK_REALTIME, &start);
    for (i = 0; i < NUM_PAGES; i++) {
        for (j = 0; j < PAGE_SIZE; j++) {
            mem[i * PAGE_SIZE + j] += 1;
        }
    }
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Elapsed time: %.6f seconds\n", elapsed);

    munmap(mem, PAGE_SIZE * NUM_PAGES);
    close(fd);

    return 0;
}