//Code Llama-13B DATASET v1.0 Category: Checksum Calculator ; Style: standalone
/*
 * checksum.c
 *
 * A standalone program that calculates the checksum of a file.
 *
 * Usage: checksum <filename>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 1;
    }

    unsigned char buffer[BUFFER_SIZE];
    int bytes_read;
    unsigned long checksum = 0;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            checksum += buffer[i];
        }
    }

    if (bytes_read == -1) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        return 1;
    }

    close(fd);

    printf("Checksum: %lu\n", checksum);

    return 0;
}