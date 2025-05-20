//GEMINI-pro DATASET v1.0 Category: System administration ; Style: scientific
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    char *buf = malloc(sb.st_size);
    if (buf == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (read(fd, buf, sb.st_size) != sb.st_size) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    close(fd);

    int i;
    for (i = 0; i < sb.st_size; i++) {
        if (buf[i] >= 'a' && buf[i] <= 'z') {
            buf[i] -= 32;
        }
    }

    fd = open(argv[1], O_WRONLY | O_TRUNC);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (write(fd, buf, sb.st_size) != sb.st_size) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    close(fd);

    free(buf);

    return EXIT_SUCCESS;
}