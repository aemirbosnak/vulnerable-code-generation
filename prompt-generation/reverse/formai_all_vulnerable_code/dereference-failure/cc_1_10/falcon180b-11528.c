//Falcon-180B DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
    long filesize;
} File;

void init_file(File *file, char *filename) {
    if (filename == NULL) {
        fprintf(stderr, "Error: filename is null\n");
        exit(1);
    }

    file->filename = strdup(filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file->file, 0, SEEK_END);
    file->filesize = ftell(file->file);
    rewind(file->file);
}

void free_file(File *file) {
    if (file->filename!= NULL) {
        free(file->filename);
    }

    if (file->file!= NULL) {
        fclose(file->file);
    }
}

char *read_line(File *file) {
    char *line = NULL;
    size_t len = 0;
    char ch;

    while ((ch = fgetc(file->file))!= EOF && ch!= '\n') {
        if (len >= MAX_LINE_LENGTH) {
            fprintf(stderr, "Error: line is too long\n");
            exit(1);
        }

        line = realloc(line, len + 2);
        if (line == NULL) {
            fprintf(stderr, "Error: out of memory\n");
            exit(1);
        }

        line[len] = ch;
        len++;
    }

    if (len > 0) {
        line[len] = '\0';
    }

    return line;
}

int main() {
    File file;
    char *line;

    init_file(&file, "example.txt");

    while ((line = read_line(&file))!= NULL) {
        printf("%s", line);
    }

    free_file(&file);

    return 0;
}