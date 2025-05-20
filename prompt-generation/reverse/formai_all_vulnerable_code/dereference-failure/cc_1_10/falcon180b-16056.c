//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    char *source_file = argv[1];
    char *dest_file = argv[2];

    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        printf("Error opening %s: %s\n", source_file, strerror(errno));
        return 1;
    }

    int dest_fd = open(dest_file, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        printf("Error opening %s: %s\n", dest_file, strerror(errno));
        close(source_fd);
        return 1;
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        printf("Error getting source file status: %s\n", strerror(errno));
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    size_t file_size = source_stat.st_size;
    char *buffer = malloc(file_size + 1);
    if (!buffer) {
        printf("Error allocating memory for buffer\n");
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    size_t bytes_read = read(source_fd, buffer, file_size);
    if (bytes_read!= file_size) {
        printf("Error reading source file: %s\n", strerror(errno));
        free(buffer);
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    buffer[bytes_read] = '\0'; // add null terminator

    size_t bytes_written = write(dest_fd, buffer, file_size);
    if (bytes_written!= file_size) {
        printf("Error writing to destination file: %s\n", strerror(errno));
        free(buffer);
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    free(buffer);
    close(source_fd);
    close(dest_fd);

    printf("File synchronization successful!\n");
    return 0;
}