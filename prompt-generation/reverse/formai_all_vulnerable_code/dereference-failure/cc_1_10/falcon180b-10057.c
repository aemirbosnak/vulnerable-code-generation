//Falcon-180B DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    FILE *fp;
    int line_number;
} file_t;

file_t *open_file(char *filename) {
    file_t *file = (file_t *)malloc(sizeof(file_t));
    strcpy(file->filename, filename);
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    file->line_number = 0;
    return file;
}

int read_line(file_t *file, char *buffer) {
    int count = 0;
    char c;
    while ((c = fgetc(file->fp))!= EOF) {
        if (c == '\n') {
            buffer[count] = '\0';
            file->line_number++;
            count = 0;
        } else if (count < MAX_LINE_LENGTH - 1) {
            buffer[count++] = c;
        }
    }
    if (count > 0) {
        buffer[count] = '\0';
        file->line_number++;
    }
    return count;
}

void close_file(file_t *file) {
    fclose(file->fp);
    free(file);
}

int main() {
    file_t *file = open_file("example.txt");
    char buffer[MAX_LINE_LENGTH];
    int count;
    while ((count = read_line(file, buffer)) > 0) {
        printf("Line %d: %s\n", file->line_number, buffer);
    }
    close_file(file);
    return 0;
}