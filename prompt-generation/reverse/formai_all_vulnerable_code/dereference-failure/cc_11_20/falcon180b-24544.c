//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    FILE *src_file = NULL, *dest_file = NULL;
    char buf[BUF_SIZE];
    size_t bytes_read;
    struct stat src_stat, dest_stat;

    src_file = fopen(argv[1], "r");
    if (src_file == NULL) {
        perror("fopen");
        return 1;
    }

    dest_file = fopen(argv[2], "w");
    if (dest_file == NULL) {
        perror("fopen");
        return 1;
    }

    if (fstat(fileno(src_file), &src_stat) == -1) {
        perror("fstat");
        return 1;
    }

    if (fstat(fileno(dest_file), &dest_stat) == -1) {
        perror("fstat");
        return 1;
    }

    if (src_stat.st_size!= dest_stat.st_size) {
        fprintf(stderr, "Files are not the same size\n");
        return 1;
    }

    while ((bytes_read = fread(buf, 1, BUF_SIZE, src_file)) > 0) {
        if (fwrite(buf, 1, bytes_read, dest_file)!= bytes_read) {
            perror("fwrite");
            return 1;
        }
    }

    if (ferror(src_file)) {
        perror("fread");
        return 1;
    }

    if (ferror(dest_file)) {
        perror("fwrite");
        return 1;
    }

    if (fclose(src_file)!= 0 || fclose(dest_file)!= 0) {
        perror("fclose");
        return 1;
    }

    return 0;
}