//Falcon-180B DATASET v1.0 Category: File handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *file_name;
    FILE *file_handle;
    int line_number;
    int num_lines;
} File;

int read_file_lines(File *file) {
    char line[MAX_LINE_LENGTH];
    int lines_read = 0;

    while (fgets(line, MAX_LINE_LENGTH, file->file_handle)!= NULL) {
        lines_read++;
    }

    file->num_lines = lines_read;

    return 0;
}

int print_file_lines(File *file, int start_line, int end_line) {
    char line[MAX_LINE_LENGTH];
    int lines_printed = 0;

    rewind(file->file_handle);

    while (fgets(line, MAX_LINE_LENGTH, file->file_handle)!= NULL) {
        if (lines_printed >= start_line && lines_printed <= end_line) {
            printf("%s", line);
        }

        lines_printed++;
    }

    return 0;
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    File file;

    printf("Enter file name: ");
    scanf("%s", file_name);

    file.file_name = file_name;
    file.file_handle = fopen(file_name, "r");

    if (file.file_handle == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file_lines(&file);

    printf("Enter starting line number: ");
    scanf("%d", &file.line_number);

    printf("Enter ending line number: ");
    scanf("%d", &file.line_number);

    print_file_lines(&file, file.line_number, file.line_number);

    fclose(file.file_handle);

    return 0;
}