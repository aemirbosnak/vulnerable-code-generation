//Falcon-180B DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *fp;
} file_t;

void open_file(file_t *file, const char *file_name) {
    strcpy(file->file_name, file_name);
    file->fp = fopen(file->file_name, "r");
    if (file->fp == NULL) {
        printf("Error: Could not open file '%s'.\n", file->file_name);
        exit(1);
    }
}

void close_file(file_t *file) {
    fclose(file->fp);
}

char *read_line(file_t *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        printf("Error: Could not allocate memory for line.\n");
        exit(1);
    }
    char *result = fgets(line, MAX_LINE_LENGTH, file->fp);
    if (result == NULL) {
        printf("Error: Could not read line from file.\n");
        exit(1);
    }
    return line;
}

void process_file(file_t *file) {
    char *line;
    while ((line = read_line(file))!= NULL) {
        printf("%s", line);
        free(line);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }
    file_t file;
    open_file(&file, argv[1]);
    process_file(&file);
    close_file(&file);
    return 0;
}