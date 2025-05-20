//Falcon-180B DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *filename;
    FILE *fp;
} File;

File *open_file(const char *filename, const char *mode) {
    File *file = (File *) malloc(sizeof(File));
    file->filename = strdup(filename);
    file->fp = fopen(filename, mode);
    if (file->fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    return file;
}

void close_file(File *file) {
    fclose(file->fp);
    free(file->filename);
    free(file);
}

int read_line(File *file, char *buffer, int max_size) {
    char c;
    int i = 0;
    while (fscanf(file->fp, "%c", &c) == 1 && c!= '\n') {
        if (i < max_size - 1) {
            buffer[i++] = c;
        } else {
            printf("Error: Line too long\n");
            exit(1);
        }
    }
    buffer[i] = '\0';
    return i;
}

int main() {
    File *input_file = open_file("input.txt", "r");
    File *output_file = open_file("output.txt", "w");

    char line[MAX_LINE_SIZE];
    while (read_line(input_file, line, MAX_LINE_SIZE) > 0) {
        if (line[0]!= '#') {
            fprintf(output_file, "%s", line);
        }
    }

    close_file(input_file);
    close_file(output_file);

    return 0;
}