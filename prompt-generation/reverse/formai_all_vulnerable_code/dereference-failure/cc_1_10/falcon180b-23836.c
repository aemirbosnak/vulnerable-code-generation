//Falcon-180B DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_SIZE 100000

typedef struct {
    char *filename;
    FILE *fp;
    int num_lines;
} File;

void open_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    file->num_lines = 0;
}

void close_file(File *file) {
    if (file->fp!= NULL) {
        fclose(file->fp);
        file->fp = NULL;
    }
    free(file->filename);
}

void read_file(File *file) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file->fp)!= NULL) {
        printf("%s", line);
        file->num_lines++;
        if (file->num_lines >= MAX_FILE_SIZE) {
            printf("Error: file is too large\n");
            exit(1);
        }
    }
}

int main() {
    File file;
    char filename[MAX_LINE_SIZE];
    printf("Enter filename: ");
    fgets(filename, MAX_LINE_SIZE, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    open_file(&file, filename);
    read_file(&file);
    close_file(&file);
    return 0;
}