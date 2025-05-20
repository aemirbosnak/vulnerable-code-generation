//Falcon-180B DATASET v1.0 Category: System administration ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 4096

void usage(char *program) {
    fprintf(stderr, "Usage: %s <filename>\n", program);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        usage(argv[0]);
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    struct stat statbuf;
    int rc = fstat(fd, &statbuf);
    if (rc == -1) {
        fprintf(stderr, "Error getting file status: %s\n", strerror(errno));
        close(fd);
        exit(1);
    }

    if (!S_ISREG(statbuf.st_mode)) {
        fprintf(stderr, "Error: %s is not a regular file\n", filename);
        close(fd);
        exit(1);
    }

    char *buffer = malloc(BUF_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        close(fd);
        exit(1);
    }

    int total_bytes_read = 0;
    int bytes_read;
    while ((bytes_read = read(fd, buffer, BUF_SIZE)) > 0) {
        total_bytes_read += bytes_read;
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    if (bytes_read == -1) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        close(fd);
        exit(1);
    }

    close(fd);
    free(buffer);
    return 0;
}