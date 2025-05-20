//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BLOCK_SIZE 512

void print_usage(char* name) {
    printf("Usage: %s <device>\n", name);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        print_usage(argv[0]);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("Error opening device: %s\n", strerror(errno));
        exit(1);
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        printf("Error getting device size: %s\n", strerror(errno));
        exit(1);
    }

    printf("Device size: %d bytes\n", sb.st_size);
    printf("Block size: %d bytes\n", BLOCK_SIZE);

    char* buffer = malloc(BLOCK_SIZE);

    int num_blocks = sb.st_size / BLOCK_SIZE;
    if (sb.st_size % BLOCK_SIZE!= 0) {
        num_blocks++;
    }

    for (int i = 0; i < num_blocks; i++) {
        off_t offset = i * BLOCK_SIZE;
        if (lseek(fd, offset, SEEK_SET) == -1) {
            printf("Error seeking to block %d: %s\n", i, strerror(errno));
            exit(1);
        }

        ssize_t bytes_read = read(fd, buffer, BLOCK_SIZE);
        if (bytes_read == -1) {
            printf("Error reading block %d: %s\n", i, strerror(errno));
            exit(1);
        } else if (bytes_read!= BLOCK_SIZE) {
            printf("Short read on block %d: expected %d bytes, got %d\n", i, BLOCK_SIZE, bytes_read);
            exit(1);
        }

        printf("Block %d:\n", i);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            printf("%02x ", buffer[j]);
        }
        printf("\n");
    }

    close(fd);
    free(buffer);

    return 0;
}