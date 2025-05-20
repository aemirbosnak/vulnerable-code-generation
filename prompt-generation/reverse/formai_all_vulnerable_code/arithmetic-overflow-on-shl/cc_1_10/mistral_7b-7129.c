//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SIZE 1024
#define MASK 0x0F
#define SHIFT 4

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_RDONLY);

    if (fd1 < 0 || fd2 < 0) {
        die("Failed to open files");
    }

    char *buf1 = mmap(NULL, SIZE, PROT_READ, MAP_PRIVATE, fd1, 0);
    char *buf2 = mmap(NULL, SIZE, PROT_READ, MAP_PRIVATE, fd2, 0);

    if (buf1 == MAP_FAILED || buf2 == MAP_FAILED) {
        die("Failed to map files to memory");
    }

    int x = 0;
    int y = 0;

    sscanf(argv[1], "%x", &x);
    sscanf(argv[2], "%x", &y);

    int res = 0;

    res |= x & y;
    res |= x ^ y;
    res |= ~x & y;
    res |= x << SHIFT & y >> MASK;

    printf("Result: 0x%X\n", res);

    munmap(buf1, SIZE);
    munmap(buf2, SIZE);

    close(fd1);
    close(fd2);

    return 0;
}