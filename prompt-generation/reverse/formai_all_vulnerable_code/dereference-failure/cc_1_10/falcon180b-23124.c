//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    char *src_file = argv[1];
    char *dst_file = argv[2];

    int src_fd = open(src_file, O_RDONLY);
    if (src_fd == -1) {
        printf("Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    int dst_fd = open(dst_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) {
        printf("Error opening destination file: %s\n", strerror(errno));
        close(src_fd);
        return 1;
    }

    struct stat src_stat, dst_stat;
    fstat(src_fd, &src_stat);
    fstat(dst_fd, &dst_stat);

    if (src_stat.st_size == dst_stat.st_size) {
        printf("Files are already synchronized.\n");
        close(src_fd);
        close(dst_fd);
        return 0;
    }

    char buf[BUF_SIZE];
    while (1) {
        int bytes_read = read(src_fd, buf, BUF_SIZE);
        if (bytes_read == 0) {
            break;
        }

        int bytes_written = write(dst_fd, buf, bytes_read);
        if (bytes_written!= bytes_read) {
            printf("Error writing to destination file: %s\n", strerror(errno));
            close(src_fd);
            close(dst_fd);
            return 1;
        }
    }

    close(src_fd);
    close(dst_fd);

    printf("Files synchronized successfully.\n");
    return 0;
}