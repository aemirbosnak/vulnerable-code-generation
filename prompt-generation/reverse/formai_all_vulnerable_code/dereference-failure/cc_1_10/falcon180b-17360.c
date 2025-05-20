//Falcon-180B DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    FILE *fp;
} file_t;

int open_file(file_t *file, const char *filename) {
    file->filename = strdup(filename);
    file->fp = fopen(filename, "r");
    if (!file->fp) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }
    return 0;
}

int close_file(file_t *file) {
    fclose(file->fp);
    free(file->filename);
    return 0;
}

int read_line(file_t *file, char *buffer) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file->fp))!= -1) {
        if (read > 0 && line[read - 1] == '\n') {
            line[--read] = '\0';
        }
        strncpy(buffer, line, MAX_LINE_SIZE);
        break;
    }

    if (line) {
        free(line);
    }

    return read;
}

int main() {
    file_t file;
    char buffer[MAX_LINE_SIZE];

    open_file(&file, "example.txt");

    while (read_line(&file, buffer) > 0) {
        printf("%s\n", buffer);
    }

    close_file(&file);

    return 0;
}