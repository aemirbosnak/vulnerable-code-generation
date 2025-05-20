//Falcon-180B DATASET v1.0 Category: File handling ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE (1024 * 1024)

typedef struct {
    char *filename;
    FILE *fp;
    size_t lines_read;
} file_t;

void init_file(file_t *file, const char *filename) {
    file->filename = strdup(filename);
    file->fp = fopen(filename, "r");
    if (!file->fp) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    file->lines_read = 0;
}

int read_line(file_t *file, char **line) {
    char buffer[MAX_LINE_LENGTH];
    size_t bytes_read = 0;

    do {
        bytes_read = fread(buffer, 1, MAX_LINE_LENGTH, file->fp);
        if (bytes_read == 0) {
            if (feof(file->fp)) {
                return 0;
            } else {
                fprintf(stderr, "Error reading file: %s\n", file->filename);
                exit(1);
            }
        }
    } while (!feof(file->fp) && buffer[bytes_read - 1]!= '\n');

    *line = strndup(buffer, bytes_read - 1);
    file->lines_read++;

    return 1;
}

void close_file(file_t *file) {
    if (file->fp) {
        fclose(file->fp);
        file->fp = NULL;
    }
    free(file->filename);
    free(file);
}

int main() {
    file_t *file = malloc(sizeof(file_t));
    init_file(file, "test.txt");

    char *line = NULL;
    while (read_line(file, &line)) {
        printf("Line %zu: %s", file->lines_read, line);
    }

    close_file(file);
    return 0;
}