//Falcon-180B DATASET v1.0 Category: File handling ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int line_number;
} File;

void open_file(File *file, const char *filename) {
    file->filename = malloc(strlen(filename) + 1);
    strcpy(file->filename, filename);
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    file->line_number = 0;
}

int read_line(File *file) {
    int c;
    int i = 0;
    file->line_number++;
    while ((c = fgetc(file->fp))!= EOF) {
        if (i >= MAX_LINE_LENGTH - 1) {
            printf("Error: Line too long.\n");
            exit(1);
        }
        if (c == '\n') {
            file->line[i] = '\0';
            break;
        }
        file->line[i] = c;
        i++;
    }
    return 1;
}

int close_file(File *file) {
    fclose(file->fp);
    free(file->filename);
    return 1;
}

int main() {
    File file;
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Opening file...\n");
    open_file(&file, filename);
    printf("Reading file...\n");
    while (read_line(&file)) {
        printf("Line %d: %s\n", file.line_number, file.line);
    }
    printf("Closing file...\n");
    close_file(&file);
    return 0;
}