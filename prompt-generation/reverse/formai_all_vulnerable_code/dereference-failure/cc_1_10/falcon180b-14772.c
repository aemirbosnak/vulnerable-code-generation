//Falcon-180B DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char* filename;
    FILE* file;
} File;

void open_file(File* file, const char* filename, const char* mode) {
    file->filename = strdup(filename);
    file->file = fopen(file->filename, mode);
    if (file->file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }
}

int read_line(File* file, char** line) {
    char* buffer = NULL;
    size_t buffer_size = 0;
    getline(&buffer, &buffer_size, file->file);
    if (buffer == NULL) {
        *line = NULL;
        return 0;
    }
    *line = strdup(buffer);
    return 1;
}

void close_file(File* file) {
    fclose(file->file);
    free(file->filename);
    free(file);
}

int main() {
    File file;
    char* line = NULL;

    open_file(&file, "example.txt", "r");

    while (read_line(&file, &line)) {
        printf("%s", line);
    }

    close_file(&file);

    return 0;
}