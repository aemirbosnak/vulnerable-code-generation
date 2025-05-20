//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct {
    char* filename;
    int fd;
    int size;
} file_t;

void init_file(file_t* file, const char* filename) {
    file->filename = strdup(filename);
    file->fd = -1;
    file->size = 0;
}

void free_file(file_t* file) {
    close(file->fd);
    free(file->filename);
    free(file);
}

void read_file(file_t* file) {
    char* buffer = malloc(file->size);
    read(file->fd, buffer, file->size);
    printf("File content:\n%s\n", buffer);
    free(buffer);
}

void write_file(file_t* file, const char* content) {
    int new_size = strlen(content);
    char* new_buffer = malloc(new_size);
    strcpy(new_buffer, content);
    free(file->filename);
    file->filename = strdup(content);
    file->size = new_size;
    free(file->filename);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <operation>\n", argv[0]);
        printf("Operations:\n");
        printf("-r: read file\n");
        printf("-w: write file\n");
        return 1;
    }

    char* filename = argv[1];
    char* operation = argv[2];

    file_t file;
    init_file(&file, filename);

    if (strcmp(operation, "-r") == 0) {
        read_file(&file);
    } else if (strcmp(operation, "-w") == 0) {
        char* content = "This is a test file.";
        write_file(&file, content);
    } else {
        printf("Invalid operation.\n");
    }

    free_file(&file);

    return 0;
}