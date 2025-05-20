//Falcon-180B DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
} File;

void open_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        fprintf(stderr, "ERROR: Failed to open file '%s'\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    fclose(file->file);
    free(file->filename);
}

char *read_line(File *file) {
    char *line = NULL;
    size_t line_length = 0;
    ssize_t bytes_read;

    while (1) {
        bytes_read = getline(&line, &line_length, file->file);
        if (bytes_read == -1) {
            if (ferror(file->file)) {
                fprintf(stderr, "ERROR: Failed to read line from file\n");
                exit(1);
            }
            break;
        }

        if (bytes_read == 0) {
            break;
        }

        if (line[bytes_read - 1] == '\n') {
            break;
        }

        char *new_line = realloc(line, line_length + MAX_LINE_LENGTH);
        if (new_line == NULL) {
            fprintf(stderr, "ERROR: Failed to allocate memory for line\n");
            exit(1);
        }
        line = new_line;
        line_length += MAX_LINE_LENGTH;
    }

    return line;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "USAGE: %s filename\n", argv[0]);
        exit(1);
    }

    File file;
    open_file(&file, argv[1]);

    char *line;
    while ((line = read_line(&file))!= NULL) {
        for (int i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                line[i] = toupper(line[i]);
            }
        }
        printf("%s", line);
        free(line);
    }

    close_file(&file);

    return 0;
}