//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage:./program <filename>\n");
        exit(1);
    }

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    struct stat stat_buf;
    if (fstat(fd, &stat_buf) == -1) {
        printf("Error getting file status: %s\n", filename);
        exit(1);
    }

    int file_size = stat_buf.st_size;
    char *buffer = malloc(file_size + 1);

    if (buffer == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    int bytes_read = read(fd, buffer, file_size);

    if (bytes_read!= file_size) {
        printf("Error reading file: %s\n", filename);
        exit(1);
    }

    buffer[file_size] = '\0';
    printf("Recovered data:\n%s\n", buffer);

    close(fd);
    free(buffer);
    return 0;
}