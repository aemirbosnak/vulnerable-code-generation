//Falcon-180B DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_LINE_COUNT 1000

typedef struct {
    char *filename;
    FILE *fp;
    int line_count;
} File;

void open_file(File *file, char *filename) {
    file->filename = strdup(filename);
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }
    file->line_count = 0;
}

char *read_line(File *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    getline(&line, &len, file->fp);
    if (line == NULL) {
        if (ferror(file->fp)) {
            fprintf(stderr, "Error reading line from file %s\n", file->filename);
            exit(1);
        }
        return NULL;
    }
    if (line[strcspn(line, "\n")]!= '\0') {
        fprintf(stderr, "Line too long in file %s\n", file->filename);
        exit(1);
    }
    file->line_count++;
    return line;
}

void close_file(File *file) {
    if (file->fp!= NULL) {
        fclose(file->fp);
        free(file->filename);
    }
}

void print_file(File *file) {
    char *line;
    while ((line = read_line(file))!= NULL) {
        printf("%s", line);
    }
}

int main() {
    File file;
    char *filename;
    printf("Enter filename: ");
    scanf("%s", filename);
    open_file(&file, filename);
    print_file(&file);
    close_file(&file);
    return 0;
}