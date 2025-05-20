//Falcon-180B DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *filename;
    FILE *file;
    char *line;
    size_t line_capacity;
    size_t line_length;
} FileReader;

void init_file_reader(FileReader *reader, const char *filename) {
    reader->filename = strdup(filename);
    reader->file = fopen(filename, "r");
    if (reader->file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }
    reader->line = malloc(MAX_LINE_LENGTH);
    reader->line_capacity = MAX_LINE_LENGTH;
    reader->line_length = 0;
}

void destroy_file_reader(FileReader *reader) {
    free(reader->filename);
    fclose(reader->file);
    free(reader->line);
}

int read_line(FileReader *reader) {
    char c;
    int ret;
    if (reader->line_length == 0) {
        ret = fgetc(reader->file);
        if (ret == EOF) {
            return 0;
        }
        c = ret;
        reader->line[0] = c;
        reader->line_length = 1;
    } else {
        ret = fread(reader->line + reader->line_length, 1, reader->line_capacity - reader->line_length, reader->file);
        if (ret == 0 && feof(reader->file)) {
            return 0;
        }
        c = reader->line[reader->line_length];
        reader->line[reader->line_length] = '\0';
        reader->line_length += ret;
    }
    return 1;
}

const char *get_filename(const FileReader *reader) {
    return reader->filename;
}

const char *get_line(const FileReader *reader) {
    return reader->line;
}

int main() {
    FileReader reader;
    init_file_reader(&reader, "nonexistent.txt");
    while (read_line(&reader)) {
        printf("Line %zu: %s\n", reader.line_length, reader.line);
    }
    destroy_file_reader(&reader);
    return 0;
}