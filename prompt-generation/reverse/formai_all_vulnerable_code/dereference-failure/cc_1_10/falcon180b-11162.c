//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 1024 * 1024 // 1 MB buffer size

void file_sync(const char *src_path, const char *dst_path) {
    FILE *src_file, *dst_file;
    char buf[BUF_SIZE];
    ssize_t bytes_read, bytes_written;
    int err;

    src_file = fopen(src_path, "r");
    if (src_file == NULL) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    dst_file = fopen(dst_path, "w");
    if (dst_file == NULL) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        exit(1);
    }

    while ((bytes_read = fread(buf, 1, BUF_SIZE, src_file)) > 0) {
        bytes_written = fwrite(buf, 1, bytes_read, dst_file);
        if (bytes_written!= bytes_read) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            exit(1);
        }
    }

    if (ferror(src_file)) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
        exit(1);
    }

    if (fflush(dst_file) == EOF) {
        fprintf(stderr, "Error flushing destination file: %s\n", strerror(errno));
        exit(1);
    }

    if (fclose(src_file) == EOF) {
        fprintf(stderr, "Error closing source file: %s\n", strerror(errno));
        exit(1);
    }

    if (fclose(dst_file) == EOF) {
        fprintf(stderr, "Error closing destination file: %s\n", strerror(errno));
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        exit(1);
    }

    file_sync(argv[1], argv[2]);

    return 0;
}