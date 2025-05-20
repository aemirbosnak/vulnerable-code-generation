//Falcon-180B DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char *filename;
    FILE *file;
} File;

int open_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    return 0;
}

int close_file(File *file) {
    fclose(file->file);
    free(file->filename);
    return 0;
}

int read_line(File *file, char *line, int max_length) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file->file))!= EOF && i < max_length - 1) {
        line[i++] = ch;
    }
    line[i] = '\0';
    return 0;
}

int count_lines(File *file) {
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file->file)!= NULL) {
        count++;
    }
    return count;
}

int main() {
    File file;
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    open_file(&file, filename);
    int line_count = count_lines(&file);
    printf("File '%s' contains %d lines.\n", file.filename, line_count);
    close_file(&file);
    return 0;
}