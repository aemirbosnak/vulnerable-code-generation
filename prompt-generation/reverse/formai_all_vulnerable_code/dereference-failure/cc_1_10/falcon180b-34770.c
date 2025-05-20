//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 1024

typedef struct {
    char *filename;
    FILE *file;
    char *line;
    int line_num;
    int line_size;
} File;

File *open_file(char *filename) {
    File *file = malloc(sizeof(File));
    file->filename = strdup(filename);
    file->file = fopen(file->filename, "r");
    if (file->file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    file->line = malloc(MAX_LINE_LENGTH);
    file->line_num = 0;
    file->line_size = 0;
    return file;
}

void close_file(File *file) {
    free(file->filename);
    free(file->line);
    fclose(file->file);
    free(file);
}

void read_line(File *file) {
    char c;
    int i = 0;
    while ((c = fgetc(file->file))!= EOF) {
        if (i == MAX_LINE_LENGTH - 1) {
            printf("Error: line too long\n");
            exit(1);
        }
        if (isspace(c)) {
            file->line[i] = '\0';
            file->line_num++;
            file->line_size = 0;
        } else {
            file->line[i++] = c;
            file->line_size++;
        }
    }
    if (i > 0) {
        file->line[i] = '\0';
        file->line_num++;
        file->line_size = 0;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    File *file = open_file(argv[1]);
    while (fgets(file->line, MAX_LINE_LENGTH, file->file)!= NULL) {
        printf("%d: %s", file->line_num, file->line);
    }
    close_file(file);
    return 0;
}