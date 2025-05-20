//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    char *source_file = argv[1];
    char *dest_file = argv[2];

    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    int dest_fd = open(dest_file, O_WRONLY | O_CREAT, 0644);
    if (dest_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        close(source_fd);
        return 1;
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        fprintf(stderr, "Error getting source file size: %s\n", strerror(errno));
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytes_read)!= bytes_read) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            close(source_fd);
            close(dest_fd);
            return 1;
        }
    }

    if (bytes_read == -1) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    close(source_fd);
    close(dest_fd);

    return 0;
}