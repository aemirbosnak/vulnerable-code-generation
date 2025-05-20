//Falcon-180B DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char *name;
    FILE *fp;
    int line_count;
} file_t;

int is_valid_file_name(char *filename) {
    int i = 0;
    while (filename[i]) {
        if (!isalpha(filename[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int is_valid_line(char *line) {
    int i = 0;
    while (line[i]) {
        if (!isalpha(line[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

void open_file(file_t *file, char *filename) {
    if (!is_valid_file_name(filename)) {
        printf("Invalid filename: %s\n", filename);
        exit(1);
    }
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    file->name = strdup(filename);
    file->line_count = 0;
}

void close_file(file_t *file) {
    fclose(file->fp);
    free(file->name);
    free(file);
}

void read_file(file_t *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file->fp)!= NULL) {
        if (is_valid_line(line)) {
            printf("%s:%d: %s\n", file->name, file->line_count, line);
        }
        file->line_count++;
    }
}

void main() {
    int i, num_files = 0;
    char filename[MAX_FILE_NAME_LENGTH];

    while (1) {
        printf("Enter filename (or type 'done' to finish): ");
        scanf("%s", filename);
        if (strcmp(filename, "done") == 0) {
            break;
        }
        num_files++;
        file_t *file = (file_t *) malloc(sizeof(file_t));
        open_file(file, filename);
        read_file(file);
        close_file(file);
    }

    printf("Processed %d files.\n", num_files);
}