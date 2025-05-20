//Falcon-180B DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *filename;
    FILE *file;
    int line_count;
} File;

File *open_file(char *filename) {
    File *file = malloc(sizeof(File));
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    file->line_count = 0;
    return file;
}

void close_file(File *file) {
    fclose(file->file);
    free(file->filename);
    free(file);
}

char *read_line(File *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file->file))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        } else {
            line = realloc(line, read + 1);
            line[read] = '\0';
        }
        file->line_count++;
        return line;
    }

    if (line!= NULL) {
        free(line);
    }
    return NULL;
}

int main() {
    char filename[MAX_LINE_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);

    File *file = open_file(filename);
    char *line = read_line(file);

    while (line!= NULL) {
        printf("%d: %s", file->line_count, line);
        line = read_line(file);
    }

    close_file(file);

    return 0;
}