//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

void file_sync(char *src_file, char *dest_file) {
    int src_fd, dest_fd;
    char buf[BUF_SIZE];
    ssize_t read_count, write_count;
    off_t offset = 0;

    src_fd = open(src_file, O_RDONLY);
    if (src_fd == -1) {
        printf("Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        printf("Error opening destination file: %s\n", strerror(errno));
        close(src_fd);
        exit(1);
    }

    while ((read_count = read(src_fd, buf, BUF_SIZE)) > 0) {
        write_count = write(dest_fd, buf, read_count);
        if (write_count!= read_count) {
            printf("Error writing to destination file: %s\n", strerror(errno));
            close(src_fd);
            close(dest_fd);
            unlink(dest_file);
            exit(1);
        }
        offset += write_count;
    }

    if (read_count == -1) {
        printf("Error reading from source file: %s\n", strerror(errno));
        close(src_fd);
        close(dest_fd);
        unlink(dest_file);
        exit(1);
    }

    close(src_fd);
    close(dest_fd);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

    file_sync(argv[1], argv[2]);

    printf("File synchronization complete.\n");
    return 0;
}