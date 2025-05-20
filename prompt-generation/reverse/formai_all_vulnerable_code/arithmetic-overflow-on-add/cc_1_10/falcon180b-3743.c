//Falcon-180B DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000 // Maximum size of the array
#define MAX_LINES 1000 // Maximum number of lines in the file
#define MAX_CHARS 100 // Maximum number of characters in a line

typedef struct {
    char *filename;
    FILE *fp;
    int num_lines;
    char **lines;
} File;

int init_file(File *file, char *filename) {
    file->filename = filename;
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }
    file->num_lines = 0;
    file->lines = NULL;
    return 1;
}

int read_file(File *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file->fp))!= -1) {
        file->num_lines++;
        file->lines = realloc(file->lines, sizeof(char *) * file->num_lines);
        file->lines[file->num_lines - 1] = strdup(line);
    }
    free(line);
    return 1;
}

int print_file(File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        printf("%s\n", file->lines[i]);
    }
    return 1;
}

int main() {
    char filename[MAX_SIZE];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    File file;
    init_file(&file, filename);

    if (read_file(&file)) {
        printf("File content:\n");
        print_file(&file);
    }

    free(file.filename);
    for (int i = 0; i < file.num_lines; i++) {
        free(file.lines[i]);
    }
    free(file.lines);
    fclose(file.fp);

    return 0;
}