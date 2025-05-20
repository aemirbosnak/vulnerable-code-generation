//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096
#define BUFFER_SIZE 1000000

int main() {
    int fd, i, j, proc_mem_fd, pages;
    char *buffer, *proc_mem;
    struct stat stat_buf;

    fd = open("/dev/zero", O_RDWR);
    if (fd == -1) {
        printf("Error opening /dev/zero\n");
        return 1;
    }

    if (fstat(fd, &stat_buf) == -1) {
        printf("Error getting file status\n");
        return 1;
    }

    pages = stat_buf.st_size / PAGE_SIZE;

    buffer = mmap(NULL, pages * PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (buffer == MAP_FAILED) {
        printf("Error mapping memory\n");
        return 1;
    }

    for (i = 0; i < pages; i++) {
        memset(buffer + i * PAGE_SIZE, 0, PAGE_SIZE);
    }

    proc_mem_fd = open("/proc/self/mem", O_RDWR);
    if (proc_mem_fd == -1) {
        printf("Error opening /proc/self/mem\n");
        return 1;
    }

    proc_mem = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, proc_mem_fd, 0);
    if (proc_mem == MAP_FAILED) {
        printf("Error mapping proc memory\n");
        return 1;
    }

    for (i = 0; i < BUFFER_SIZE; i += PAGE_SIZE) {
        for (j = 0; j < pages; j++) {
            if (memcmp(proc_mem + i + j * PAGE_SIZE, buffer + j * PAGE_SIZE, PAGE_SIZE)!= 0) {
                printf("Memory corruption detected\n");
                return 1;
            }
        }
    }

    printf("RAM usage monitoring started\n");

    while (1) {
        usleep(100000);

        for (i = 0; i < BUFFER_SIZE; i += PAGE_SIZE) {
            for (j = 0; j < pages; j++) {
                if (memcmp(proc_mem + i + j * PAGE_SIZE, buffer + j * PAGE_SIZE, PAGE_SIZE)!= 0) {
                    printf("Memory corruption detected\n");
                    return 1;
                }
            }
        }
    }

    return 0;
}