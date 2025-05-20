//Falcon-180B DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILENAME_LENGTH 100

typedef struct {
    char *filename;
    FILE *file;
    int line_count;
} File;

void open_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(file->filename, "r");
    if (file->file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    file->line_count = 0;
}

void close_file(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
        free(file->filename);
        file->filename = NULL;
        file->file = NULL;
    }
}

int read_line(File *file, char *buffer, int max_length) {
    char c;
    int length = 0;
    while ((c = fgetc(file->file))!= EOF && length < max_length - 1) {
        buffer[length] = c;
        length++;
    }
    buffer[length] = '\0';
    if (length == 0) {
        return 0;
    }
    file->line_count++;
    return 1;
}

void print_file_contents(File *file) {
    char buffer[MAX_LINE_LENGTH];
    int length;
    while ((length = read_line(file, buffer, MAX_LINE_LENGTH)) > 0) {
        printf("%d: %s\n", file->line_count, buffer);
    }
}

int main() {
    File file;
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename);
    open_file(&file, filename);
    print_file_contents(&file);
    close_file(&file);
    return 0;
}