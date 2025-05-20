//Falcon-180B DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
} FileHandle;

void open_file(FileHandle *file_handle, const char *filename) {
    file_handle->filename = strdup(filename);
    file_handle->file = fopen(filename, "r");
    if (file_handle->file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
}

void close_file(FileHandle *file_handle) {
    if (file_handle->file!= NULL) {
        fclose(file_handle->file);
        free(file_handle->filename);
    }
}

char *read_line(FileHandle *file_handle, char *buffer, int buffer_size) {
    char *line = fgets(buffer, buffer_size, file_handle->file);
    if (line == NULL) {
        if (ferror(file_handle->file)) {
            printf("Error reading file: %s\n", file_handle->filename);
            exit(1);
        }
        return NULL;
    }
    return line;
}

int count_lines(FileHandle *file_handle) {
    int count = 0;
    char buffer[MAX_LINE_LENGTH];
    char *line;

    while ((line = read_line(file_handle, buffer, MAX_LINE_LENGTH))!= NULL) {
        count++;
    }

    return count;
}

int main() {
    FileHandle file_handle;
    char filename[MAX_LINE_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    open_file(&file_handle, filename);

    int line_count = count_lines(&file_handle);

    printf("File '%s' has %d lines.\n", file_handle.filename, line_count);

    close_file(&file_handle);

    return 0;
}