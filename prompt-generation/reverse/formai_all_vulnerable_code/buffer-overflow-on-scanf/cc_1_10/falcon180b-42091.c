//Falcon-180B DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

typedef struct {
    char *filename;
    FILE *fp;
} File;

void init_file(File *file, char *filename) {
    file->filename = filename;
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    fclose(file->fp);
    free(file->filename);
    free(file);
}

int read_line(File *file, char *buffer, int max_size) {
    char ch;
    int count = 0;
    do {
        ch = fgetc(file->fp);
        if (ch == EOF || count >= max_size - 1) {
            buffer[count] = '\0';
            return count;
        }
        buffer[count++] = ch;
    } while (ch!= '\n');
    buffer[count++] = '\0';
    return count;
}

int count_lines(File *file) {
    int line_count = 0;
    char ch;
    do {
        ch = fgetc(file->fp);
        if (ch == '\n') {
            line_count++;
        }
    } while (ch!= EOF);
    return line_count;
}

int main() {
    char filename[256];
    printf("Enter filename: ");
    scanf("%s", filename);

    File *file = (File *)malloc(sizeof(File));
    init_file(file, filename);

    int line_count = count_lines(file);
    printf("File has %d lines\n", line_count);

    char buffer[BUFFER_SIZE];
    int max_size = BUFFER_SIZE - 1;
    for (int i = 0; i < line_count; i++) {
        int line_size = read_line(file, buffer, max_size);
        printf("Line %d: %s", i+1, buffer);
    }

    close_file(file);
    return 0;
}