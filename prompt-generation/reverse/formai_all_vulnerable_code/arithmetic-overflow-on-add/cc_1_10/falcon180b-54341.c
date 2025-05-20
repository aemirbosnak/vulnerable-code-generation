//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        exit(1);
    }

    char *file_path = argv[1];
    int file_fd = open(file_path, O_RDONLY);

    if (file_fd == -1) {
        printf("Cannot open file %s\n", file_path);
        exit(1);
    }

    struct stat file_stat;
    if (fstat(file_fd, &file_stat) == -1) {
        printf("Cannot get file status\n");
        exit(1);
    }

    int file_size = file_stat.st_size;
    char *file_buf = malloc(file_size + 1);
    int read_size;

    if (file_buf == NULL) {
        printf("Cannot allocate memory\n");
        exit(1);
    }

    read_size = read(file_fd, file_buf, file_size);

    if (read_size!= file_size) {
        printf("Cannot read file\n");
        exit(1);
    }

    file_buf[file_size] = '\0';
    char *file_copy = malloc(file_size + 1);

    if (file_copy == NULL) {
        printf("Cannot allocate memory\n");
        exit(1);
    }

    int copy_size = 0;
    int i, j;

    for (i = 0; i < file_size; i += BUF_SIZE) {
        j = i + BUF_SIZE;
        if (j > file_size) {
            j = file_size;
        }

        memcpy(file_copy + copy_size, file_buf + i, j - i);
        copy_size += j - i;
    }

    close(file_fd);
    free(file_buf);

    printf("File copied to memory\n");

    return 0;
}