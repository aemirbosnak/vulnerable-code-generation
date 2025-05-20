//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <source file> <destination file> <block size>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int src_fd, dst_fd;
    struct stat src_stat, dst_stat;
    char buf[BUFSIZE];
    int nread, nwritten;
    int block_size = atoi(argv[3]);

    // Open the source file.
    src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Get the size of the source file.
    if (fstat(src_fd, &src_stat) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    // Open the destination file.
    dst_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Get the size of the destination file.
    if (fstat(dst_fd, &dst_stat) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    // If the destination file is smaller than the source file, truncate it.
    if (dst_stat.st_size < src_stat.st_size) {
        if (ftruncate(dst_fd, src_stat.st_size) == -1) {
            perror("ftruncate");
            return EXIT_FAILURE;
        }
    }

    // Synchronize the files.
    while ((nread = read(src_fd, buf, block_size)) > 0) {
        if (write(dst_fd, buf, nread) != nread) {
            perror("write");
            return EXIT_FAILURE;
        }
    }

    // Close the files.
    if (close(src_fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    if (close(dst_fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}