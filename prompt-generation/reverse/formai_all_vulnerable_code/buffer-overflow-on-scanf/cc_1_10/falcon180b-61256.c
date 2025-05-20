//Falcon-180B DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
    int line_count;
} File;

void init_file(File *file, char *filename) {
    file->filename = filename;
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    file->line_count = 0;
}

int read_line(File *file, char *buffer, int max_length) {
    char c;
    int i = 0;
    while ((c = fgetc(file->file))!= EOF && i < max_length - 1) {
        if (c == '\n') {
            file->line_count++;
        }
        buffer[i++] = c;
    }
    buffer[i] = '\0';
    return i;
}

void print_line(File *file, int line_number, char *buffer, int length) {
    printf("%d: %.*s\n", line_number, length, buffer);
}

void print_file_contents(File *file) {
    char buffer[MAX_LINE_LENGTH];
    int length;
    while ((length = read_line(file, buffer, MAX_LINE_LENGTH)) > 0) {
        print_line(file, file->line_count, buffer, length);
    }
}

void close_file(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    File file;
    init_file(&file, filename);
    print_file_contents(&file);
    close_file(&file);
    return 0;
}