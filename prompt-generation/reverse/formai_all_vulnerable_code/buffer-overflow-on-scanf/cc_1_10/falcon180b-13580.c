//Falcon-180B DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000 // Maximum line size
#define MAX_FILE_NAME_SIZE 100 // Maximum file name size

typedef struct {
    char line[MAX_LINE_SIZE]; // Line buffer
    int line_number; // Line number
} Line;

typedef struct {
    FILE* file; // File pointer
    char file_name[MAX_FILE_NAME_SIZE]; // File name
} File;

void open_file(File* file, const char* file_name) {
    strncpy(file->file_name, file_name, MAX_FILE_NAME_SIZE);
    file->file = fopen(file->file_name, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        exit(1);
    }
}

void close_file(File* file) {
    fclose(file->file);
}

int read_line(File* file, Line* line) {
    char* buffer = fgets(line->line, MAX_LINE_SIZE, file->file);
    if (buffer == NULL) {
        return 0; // End of file
    }
    line->line_number++;
    return 1;
}

void print_line(Line* line) {
    printf("%d: %s", line->line_number, line->line);
}

int main() {
    char file_name[MAX_FILE_NAME_SIZE];
    printf("Enter file name: ");
    scanf("%s", file_name);

    File file;
    open_file(&file, file_name);

    Line line;
    while (read_line(&file, &line)) {
        print_line(&line);
    }

    close_file(&file);
    return 0;
}