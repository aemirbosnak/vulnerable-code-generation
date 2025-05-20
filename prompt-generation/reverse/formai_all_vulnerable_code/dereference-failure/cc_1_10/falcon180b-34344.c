//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 8192

void sync_files(char *source_file, char *dest_file) {
    int source_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;
    off_t file_size;

    source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    dest_fd = open(dest_file, O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (dest_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        exit(1);
    }

    file_size = lseek(source_fd, 0, SEEK_END);
    if (file_size == -1) {
        fprintf(stderr, "Error getting source file size: %s\n", strerror(errno));
        exit(1);
    }

    lseek(dest_fd, file_size - 1, SEEK_SET);
    write(dest_fd, "", 1);

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            exit(1);
        }
    }

    close(source_fd);
    close(dest_fd);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <source_file> <dest_file>\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    fprintf(stdout, "Files synchronized successfully!\n");

    return 0;
}