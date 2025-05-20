//Falcon-180B DATASET v1.0 Category: Error handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char *filename;
    FILE *fp;
} file_t;

void open_file(file_t *file, const char *filename) {
    file->filename = strdup(filename);
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }
}

void close_file(file_t *file) {
    if (file->fp!= NULL) {
        fclose(file->fp);
        free(file->filename);
    }
}

char *read_line(file_t *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (getline(&line, &len, file->fp) == -1) {
        if (ferror(file->fp)) {
            printf("Error: Failed to read line from file '%s'\n", file->filename);
            exit(1);
        } else {
            line = strdup("");
        }
    }

    if (line!= NULL && line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
    }

    return line;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file_t file;
    open_file(&file, argv[1]);

    char *line;
    while ((line = read_line(&file))!= NULL) {
        printf("%s", line);
    }

    close_file(&file);
    return 0;
}