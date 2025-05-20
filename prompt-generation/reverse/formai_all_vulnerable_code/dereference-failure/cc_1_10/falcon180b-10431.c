//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Linus Torvalds
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
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        printf("Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        printf("Error getting source file status: %s\n", strerror(errno));
        close(source_fd);
        return 1;
    }

    int destination_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, source_stat.st_mode);
    if (destination_fd == -1) {
        printf("Error opening destination file: %s\n", strerror(errno));
        close(source_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        ssize_t bytes_written = write(destination_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            printf("Error writing to destination file: %s\n", strerror(errno));
            close(source_fd);
            close(destination_fd);
            unlink(argv[2]);
            return 1;
        }
    }

    if (bytes_read == -1) {
        printf("Error reading from source file: %s\n", strerror(errno));
        close(source_fd);
        close(destination_fd);
        unlink(argv[2]);
        return 1;
    }

    close(source_fd);
    close(destination_fd);

    printf("Data recovery completed successfully.\n");
    return 0;
}