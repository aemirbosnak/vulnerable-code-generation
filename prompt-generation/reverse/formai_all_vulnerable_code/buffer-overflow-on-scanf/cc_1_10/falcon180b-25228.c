//Falcon-180B DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char file_name[MAX_LINE_LENGTH];
    FILE* file;
} File;

void open_file(File* file, char* file_name) {
    strcpy(file->file_name, file_name);
    file->file = fopen(file->file_name, "r");
    if (file->file == NULL) {
        printf("Error: Failed to open file %s\n", file_name);
        exit(1);
    }
}

void close_file(File* file) {
    fclose(file->file);
}

int is_eof(FILE* file) {
    int c = fgetc(file);
    if (c == EOF) {
        return 1;
    } else {
        ungetc(c, file);
        return 0;
    }
}

void read_line(File* file, char* line) {
    fgets(line, MAX_LINE_LENGTH, file->file);
}

void print_file_contents(File* file) {
    char line[MAX_LINE_LENGTH];
    while (!is_eof(file->file)) {
        read_line(file, line);
        printf("%s", line);
    }
}

int main() {
    File file;
    char file_name[MAX_LINE_LENGTH];
    printf("Enter file name: ");
    scanf("%s", file_name);
    open_file(&file, file_name);
    print_file_contents(&file);
    close_file(&file);
    return 0;
}