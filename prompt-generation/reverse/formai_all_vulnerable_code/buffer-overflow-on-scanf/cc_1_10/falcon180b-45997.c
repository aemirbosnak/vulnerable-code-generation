//Falcon-180B DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char* file_name;
    FILE* file;
    int line_number;
} File;

void init_file(File* file, const char* file_name) {
    file->file_name = strdup(file_name);
    file->file = fopen(file_name, "r");
    if (file->file == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }
    file->line_number = 0;
}

void close_file(File* file) {
    fclose(file->file);
    free(file->file_name);
}

int read_line(File* file, char* buffer) {
    char* line = fgets(buffer, MAX_LINE_LENGTH, file->file);
    if (line == NULL) {
        return 0;
    }
    file->line_number++;
    return strlen(line);
}

int main() {
    File file;
    char buffer[MAX_LINE_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];

    printf("Enter file name: ");
    scanf("%s", file_name);

    init_file(&file, file_name);

    while (read_line(&file, buffer) > 0) {
        printf("%d: %s", file.line_number, buffer);
    }

    close_file(&file);

    return 0;
}