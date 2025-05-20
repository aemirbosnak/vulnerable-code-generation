//Falcon-180B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
} File;

void open_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(file->filename, "r");
    if (file->file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
    }
    free(file->filename);
}

char *read_line(File *file) {
    char *line = NULL;
    size_t line_length = 0;
    ssize_t bytes_read;
    while ((bytes_read = getline(&line, &line_length, file->file))!= -1) {
        if (bytes_read > 0 && line[bytes_read - 1] == '\n') {
            line[--bytes_read] = '\0';
        } else {
            line = realloc(line, bytes_read + 1);
        }
    }
    if (bytes_read == -1) {
        if (ferror(file->file)) {
            fprintf(stderr, "Error reading file '%s'\n", file->filename);
            exit(1);
        }
    }
    return line;
}

void print_file_contents(File *file) {
    char *line;
    while ((line = read_line(file))!= NULL) {
        printf("%s", line);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }
    File file;
    open_file(&file, argv[1]);
    print_file_contents(&file);
    close_file(&file);
    return 0;
}