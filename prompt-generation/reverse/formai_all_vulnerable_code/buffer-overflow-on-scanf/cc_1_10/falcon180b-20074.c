//Falcon-180B DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *file_name;
    FILE *file_pointer;
    int line_number;
    char line[MAX_LINE_LENGTH];
    int line_length;
} File;

void open_file(File *file, char *file_name) {
    file->file_pointer = fopen(file_name, "r");
    if (file->file_pointer == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        exit(1);
    }
    file->line_number = 0;
    file->line_length = 0;
}

void close_file(File *file) {
    fclose(file->file_pointer);
    file->file_pointer = NULL;
}

int read_line(File *file) {
    char c;
    int i = 0;
    while ((c = fgetc(file->file_pointer))!= EOF) {
        if (i >= MAX_LINE_LENGTH - 1) {
            printf("Error: Line too long\n");
            exit(1);
        }
        file->line[i++] = c;
    }
    file->line[i] = '\0';
    file->line_number++;
    file->line_length = i;
    return 1;
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", file_name);

    File file;
    open_file(&file, file_name);

    while (read_line(&file)) {
        printf("Line %d: %s\n", file.line_number, file.line);
    }

    close_file(&file);
    return 0;
}