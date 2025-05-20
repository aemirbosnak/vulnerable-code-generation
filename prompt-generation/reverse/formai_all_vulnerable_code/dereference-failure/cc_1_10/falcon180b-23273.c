//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PAGE_SIZE 4096
#define MAP_SIZE (10 * PAGE_SIZE)

int main(int argc, char *argv[]) {
    char *filename = "boot.img";
    int fd;
    void *addr;
    struct stat sb;

    if (stat(filename, &sb) == -1) {
        printf("File not found\n");
        exit(1);
    }

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Failed to open file\n");
        exit(1);
    }

    addr = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        printf("Failed to map file\n");
        exit(1);
    }

    printf("Mapped file at %p\n", addr);

    for (int i = 0; i < sb.st_size; i += PAGE_SIZE) {
        if (i % PAGE_SIZE == 0) {
            printf("Page %d:\n", i / PAGE_SIZE);
        }

        int count = 0;
        unsigned char *ptr = (unsigned char *)addr + i;

        while (*ptr!= 0 && count < 16) {
            printf(" %02X", *ptr);
            ptr++;
            count++;
        }

        while (count < 16) {
            printf("   ");
            count++;
        }

        printf("\n");
    }

    munmap(addr, sb.st_size);
    close(fd);

    return 0;
}