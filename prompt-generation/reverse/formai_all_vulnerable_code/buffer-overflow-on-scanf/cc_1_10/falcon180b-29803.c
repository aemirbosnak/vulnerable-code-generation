//Falcon-180B DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char filename[MAX_LINE_LENGTH];
    FILE *fp;
} File;

void open_file(File *file, char *filename);
void read_file(File *file, char *buffer);
void write_file(File *file, char *buffer);
void close_file(File *file);

int main() {
    File my_file;
    char buffer[MAX_LINE_LENGTH];

    printf("Enter file name: ");
    scanf("%s", my_file.filename);

    open_file(&my_file, my_file.filename);

    while (fgets(buffer, MAX_LINE_LENGTH, stdin)) {
        write_file(&my_file, buffer);
    }

    close_file(&my_file);

    printf("File saved successfully!\n");
    return 0;
}

void open_file(File *file, char *filename) {
    file->fp = fopen(filename, "a");
    if (file->fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
}

void read_file(File *file, char *buffer) {
    fgets(buffer, MAX_LINE_LENGTH, file->fp);
}

void write_file(File *file, char *buffer) {
    fputs(buffer, file->fp);
}

void close_file(File *file) {
    fclose(file->fp);
}