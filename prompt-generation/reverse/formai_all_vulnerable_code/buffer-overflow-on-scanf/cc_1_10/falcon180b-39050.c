//Falcon-180B DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    FILE *fp;
} File;

int open_file(char *filename, File *file) {
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    file->filename = strdup(filename);
    return 0;
}

int close_file(File *file) {
    if (file->fp!= NULL) {
        fclose(file->fp);
        file->fp = NULL;
    }
    free(file->filename);
    return 0;
}

int read_line(File *file, char *buffer, int max_size) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file->fp))!= -1) {
        if (strlen(line) >= max_size - 1) { // leave room for null terminator
            printf("Error: Line is too long\n");
            return 1;
        }
        strcpy(buffer, line);
        return 0;
    }

    if (ferror(file->fp)) {
        printf("Error: Could not read file\n");
        return 1;
    }

    if (feof(file->fp)) {
        return 1;
    }

    return 0;
}

int main() {
    char filename[MAX_LINE_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);

    File file;
    open_file(filename, &file);

    char buffer[MAX_LINE_SIZE];
    while (read_line(&file, buffer, MAX_LINE_SIZE) == 0) {
        printf("%s\n", buffer);
    }

    close_file(&file);
    return 0;
}