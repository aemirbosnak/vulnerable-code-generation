#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 1024
#define CACHE_SIZE 64

void main() {
    char *cache;
    char *dataFile = "large_data_file.bin";
    int fd;
    char buffer[SIZE];
    int i, j, k;

    fd = open(dataFile, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    cache = mmap(NULL, CACHE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, fd, 0);
    if (cache == MAP_FAILED) {
        perror("Error creating cache");
        return;
    }

    while ((read(fd, buffer, SIZE)) > 0) {
        for (i = 0; i < CACHE_SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                for (k = 0; k < SIZE; k++) {
                    cache[(i * SIZE * SIZE) + (j * SIZE) + k] = buffer[k];
                }
                cache[(i * SIZE * SIZE) + (j * SIZE) + SIZE] = '\0';
                printf("%s\n", &cache[(i * SIZE * SIZE) + (j * SIZE)]);

                // Dereference cache out of bounds to trigger cache eviction
                char *ptr = &cache[((i + 1) * SIZE * SIZE) + (j * SIZE)];
                printf("%c", *ptr);
            }
        }
    }

    munmap(cache, CACHE_SIZE);
    close(fd);
}
