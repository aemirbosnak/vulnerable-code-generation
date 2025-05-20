//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define BLOCK_SIZE 512
#define MAX_FILE_SIZE 1000000000 // 1GB

typedef struct {
    char* filename;
    int size;
    char* data;
} file_t;

void read_file(file_t* file) {
    int fd = open(file->filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", file->filename);
        exit(1);
    }

    file->size = lseek(fd, 0, SEEK_END);
    if (file->size == -1) {
        printf("Error getting file size: %s\n", file->filename);
        exit(1);
    }

    if (file->size > MAX_FILE_SIZE) {
        printf("File too large: %s\n", file->filename);
        exit(1);
    }

    file->data = malloc(file->size);
    if (file->data == NULL) {
        printf("Error allocating memory for file: %s\n", file->filename);
        exit(1);
    }

    int bytes_read = 0;
    while (bytes_read < file->size) {
        int count = read(fd, file->data + bytes_read, file->size - bytes_read);
        if (count == -1) {
            printf("Error reading file: %s\n", file->filename);
            exit(1);
        }
        bytes_read += count;
    }

    close(fd);
}

int main() {
    file_t* file = malloc(sizeof(file_t));
    if (file == NULL) {
        printf("Error allocating memory for file\n");
        exit(1);
    }

    printf("Enter filename: ");
    scanf("%s", file->filename);

    read_file(file);

    printf("File data:\n");
    for (int i = 0; i < file->size; i++) {
        printf("%02X ", (unsigned char)file->data[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }

    free(file->data);
    free(file);

    return 0;
}