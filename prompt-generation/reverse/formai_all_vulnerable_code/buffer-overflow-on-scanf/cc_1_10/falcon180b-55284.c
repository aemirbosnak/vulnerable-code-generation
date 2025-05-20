//Falcon-180B DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *filename;
    FILE *file;
    char buffer[MAX_LINE_LENGTH];
} File;

void init_file(File *file, const char *filename) {
    file->filename = (char *)malloc(MAX_FILE_NAME_LENGTH * sizeof(char));
    strcpy(file->filename, filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    memset(file->buffer, 0, MAX_LINE_LENGTH * sizeof(char));
}

void close_file(File *file) {
    free(file->filename);
    fclose(file->file);
}

int read_line(File *file, char *line) {
    int num_chars_read = 0;
    while (fgets(file->buffer, MAX_LINE_LENGTH, file->file)!= NULL) {
        strncpy(line, file->buffer, MAX_LINE_LENGTH);
        num_chars_read = strlen(line);
        break;
    }
    return num_chars_read;
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    File file;
    init_file(&file, filename);

    char line[MAX_LINE_LENGTH];
    int num_lines_read = 0;

    while (read_line(&file, line) > 0) {
        printf("%s", line);
        num_lines_read++;
    }

    if (num_lines_read == 0) {
        printf("File is empty\n");
    }

    close_file(&file);
    return 0;
}