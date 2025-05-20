//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        fprintf(stderr, "Error getting source file status: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytes_read)!= bytes_read) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (close(source_fd) == -1) {
        fprintf(stderr, "Error closing source file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (close(dest_fd) == -1) {
        fprintf(stderr, "Error closing destination file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}