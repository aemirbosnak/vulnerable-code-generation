//Falcon-180B DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
} File;

bool open_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return false;
    }
    return true;
}

void close_file(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
        free(file->filename);
    }
}

char *read_line(File *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    char *result = fgets(line, MAX_LINE_LENGTH, file->file);
    if (result == NULL) {
        printf("Error: could not read line from file\n");
        exit(1);
    }
    return line;
}

int main() {
    File file;
    if (!open_file(&file, "example.txt")) {
        return 1;
    }

    char *line;
    int line_number = 1;
    while ((line = read_line(&file))!= NULL) {
        printf("%d: %s", line_number, line);
        line_number++;
    }

    close_file(&file);
    return 0;
}