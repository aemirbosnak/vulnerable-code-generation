//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file_name> <offset>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    int offset = atoi(argv[2]);

    int fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    struct stat file_info;
    fstat(fd, &file_info);

    int file_size = file_info.st_size;
    if (offset < 0 || offset > file_size) {
        printf("Invalid offset: %d\n", offset);
        return 1;
    }

    int read_size = file_size - offset;
    char *buffer = (char *)malloc(read_size + 1);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    int bytes_read = read(fd, buffer, read_size);
    if (bytes_read == -1) {
        printf("Error reading file: %s\n", strerror(errno));
        return 1;
    }

    buffer[bytes_read] = '\0';
    printf("Data recovered: %s\n", buffer);

    free(buffer);
    close(fd);

    return 0;
}