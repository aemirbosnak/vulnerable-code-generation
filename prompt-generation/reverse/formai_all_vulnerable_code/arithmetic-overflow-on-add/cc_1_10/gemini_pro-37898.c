//GEMINI-pro DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the file for reading.
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Get the file size.
    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    // Allocate a buffer to hold the file contents.
    char *buffer = malloc(statbuf.st_size + 1);
    if (buffer == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Read the file contents into the buffer.
    ssize_t bytes_read = read(fd, buffer, statbuf.st_size);
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Close the file.
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    // Null-terminate the buffer.
    buffer[bytes_read] = '\0';

    // Print the file contents to stdout.
    printf("%s", buffer);

    // Free the buffer.
    free(buffer);

    return EXIT_SUCCESS;
}