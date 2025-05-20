//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#define CHUNK_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

    char *source_file = argv[1];
    char *dest_file = argv[2];

    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        printf("Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        printf("Error getting source file status: %s\n", strerror(errno));
        close(source_fd);
        exit(1);
    }

    int dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, source_stat.st_mode);
    if (dest_fd == -1) {
        printf("Error opening destination file: %s\n", strerror(errno));
        close(source_fd);
        exit(1);
    }

    char *buffer = malloc(CHUNK_SIZE);
    int bytes_read;

    while ((bytes_read = read(source_fd, buffer, CHUNK_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytes_read)!= bytes_read) {
            printf("Error writing to destination file: %s\n", strerror(errno));
            close(source_fd);
            close(dest_fd);
            free(buffer);
            exit(1);
        }
    }

    if (bytes_read == -1) {
        printf("Error reading from source file: %s\n", strerror(errno));
        close(source_fd);
        close(dest_fd);
        free(buffer);
        exit(1);
    }

    printf("Data recovery successful!\n");

    close(source_fd);
    close(dest_fd);
    free(buffer);

    return 0;
}