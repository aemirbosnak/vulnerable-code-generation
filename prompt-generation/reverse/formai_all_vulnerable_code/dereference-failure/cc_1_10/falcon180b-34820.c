//Falcon-180B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char* filename;
    FILE* fp;
} File;

File* file_open(const char* filename, const char* mode) {
    File* file = malloc(sizeof(File));
    file->filename = strdup(filename);
    file->fp = fopen(filename, mode);
    if (file->fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    return file;
}

int file_close(File* file) {
    int ret = fclose(file->fp);
    free(file->filename);
    free(file);
    return ret;
}

int file_write(File* file, const char* data) {
    return fputs(data, file->fp);
}

char* file_read(File* file) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file->fp))!= -1) {
        if (line[read-1] == '\n') {
            line[read-1] = '\0';
        }
        break;
    }
    return line;
}

void file_rewind(File* file) {
    rewind(file->fp);
}

int main() {
    File* file = file_open("example.txt", "w");
    file_write(file, "Hello, world!\n");
    file_write(file, "This is a test.\n");
    file_close(file);

    file = file_open("example.txt", "r");
    char* line = file_read(file);
    while (line!= NULL) {
        printf("%s", line);
        line = file_read(file);
    }
    file_close(file);

    return 0;
}