//Falcon-180B DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
} File;

void open_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    fclose(file->file);
    free(file->filename);
}

char *read_line(File *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file->file))!= -1) {
        if (read > 0 && line[read - 1] == '\n') {
            line[--read] = '\0';
        } else {
            line = realloc(line, read + 1);
        }
    }

    return line;
}

void print_line(const char *line) {
    printf("%s", line);
}

int main() {
    File file;
    char *line;

    open_file(&file, "example.txt");

    while ((line = read_line(&file))!= NULL) {
        print_line(line);
    }

    close_file(&file);

    return 0;
}