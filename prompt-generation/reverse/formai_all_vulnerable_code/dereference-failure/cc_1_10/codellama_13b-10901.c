//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int fd_src, fd_dst;
    char buf[BUF_SIZE];
    int nread;
    int nwritten;
    int i;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    if ((fd_src = open(argv[1], O_RDONLY)) == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    if ((fd_dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        close(fd_src);
        return 1;
    }

    while ((nread = read(fd_src, buf, BUF_SIZE)) > 0) {
        for (i = 0; i < nread; i++) {
            buf[i] = toupper(buf[i]);
        }
        nwritten = write(fd_dst, buf, nread);
        if (nwritten != nread) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            close(fd_src);
            close(fd_dst);
            return 1;
        }
    }

    if (nread == -1) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
        close(fd_src);
        close(fd_dst);
        return 1;
    }

    close(fd_src);
    close(fd_dst);
    return 0;
}