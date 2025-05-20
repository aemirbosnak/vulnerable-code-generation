//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 1024 * 1024 //1MB buffer size

void sync_files(char *src_file, char *dest_file) {
    int src_fd, dest_fd;
    char buf[BUF_SIZE];
    off_t src_size, dest_size, bytes_to_copy;
    int ret;

    src_fd = open(src_file, O_RDONLY);
    if (src_fd == -1) {
        perror("open");
        exit(1);
    }

    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("open");
        exit(1);
    }

    src_size = lseek(src_fd, 0, SEEK_END);
    if (src_size == -1) {
        perror("lseek");
        exit(1);
    }

    dest_size = lseek(dest_fd, 0, SEEK_END);
    if (dest_size == -1) {
        perror("lseek");
        exit(1);
    }

    if (src_size < dest_size) {
        printf("Source file is smaller than destination file.\n");
        exit(1);
    }

    bytes_to_copy = src_size - dest_size;

    while (bytes_to_copy > 0) {
        ret = read(src_fd, buf, BUF_SIZE);
        if (ret == -1) {
            perror("read");
            exit(1);
        }

        if (ret == 0) {
            printf("End of file reached.\n");
            break;
        }

        ret = write(dest_fd, buf, ret);
        if (ret == -1) {
            perror("write");
            exit(1);
        }

        bytes_to_copy -= ret;
    }

    close(src_fd);
    close(dest_fd);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}