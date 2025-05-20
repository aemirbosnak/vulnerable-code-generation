//Falcon-180B DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *filename;
    FILE *file;
    int linenumber;
} file_t;

void error_handler(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

bool open_file(const char *filename, file_t *file) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");

    if (file->file == NULL) {
        error_handler("Failed to open file");
        return false;
    }

    return true;
}

bool close_file(file_t *file) {
    if (fclose(file->file)!= 0) {
        error_handler("Failed to close file");
        return false;
    }

    free(file->filename);

    return true;
}

bool read_line(file_t *file, char **line) {
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t bytes_read;

    bytes_read = getline(&buffer, &buffer_size, file->file);

    if (bytes_read <= 0) {
        if (bytes_read == -1) {
            error_handler("Failed to read line");
        } else {
            fprintf(stderr, "Unexpected end of file\n");
        }

        return false;
    }

    *line = strdup(buffer);

    return true;
}

bool process_line(const char *line, int linenumber) {
    // Do some processing on the line here
    return true;
}

bool process_file(const char *filename) {
    file_t file;
    char *line = NULL;
    int linenumber = 1;

    if (!open_file(filename, &file)) {
        return false;
    }

    while (read_line(&file, &line)) {
        if (!process_line(line, linenumber)) {
            error_handler("Error processing line");
            close_file(&file);
            return false;
        }

        linenumber++;
    }

    close_file(&file);

    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        error_handler("Usage: program filename");
        return EXIT_FAILURE;
    }

    if (!process_file(argv[1])) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}