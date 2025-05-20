//Falcon-180B DATASET v1.0 Category: File handling ; Style: peaceful
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
    file->file = fopen(file->filename, "r");
    if (file->file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
        free(file->filename);
    }
}

int read_line(File *file, char *buffer, int max_length) {
    char c;
    int length = 0;

    while ((c = fgetc(file->file))!= EOF) {
        if (length >= max_length - 1) {
            fprintf(stderr, "Line too long in file '%s'\n", file->filename);
            exit(1);
        }
        buffer[length++] = c;
        if (c == '\n') {
            break;
        }
    }

    buffer[length] = '\0';
    return length;
}

void process_file(File *file) {
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    while (read_line(file, line, MAX_LINE_LENGTH) > 0) {
        line_number++;
        printf("Line %d: %s\n", line_number, line);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    File file;
    open_file(&file, argv[1]);
    process_file(&file);
    close_file(&file);

    return 0;
}