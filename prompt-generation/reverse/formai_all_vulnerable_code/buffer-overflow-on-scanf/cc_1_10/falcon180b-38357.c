//Falcon-180B DATASET v1.0 Category: File handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    FILE *file;
} File;

void open_file(File *file, char *filename) {
    strncpy(file->filename, filename, MAX_FILE_NAME_LENGTH);
    file->file = fopen(file->filename, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }
}

int read_line(char *line, FILE *file) {
    int length = 0;
    char c;
    while ((c = fgetc(file))!= EOF) {
        if (length >= MAX_LINE_LENGTH - 1) {
            printf("Error: Line too long.\n");
            exit(1);
        }
        line[length++] = c;
        if (c == '\n') {
            break;
        }
    }
    line[length] = '\0';
    return length;
}

void close_file(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
        file->file = NULL;
    }
}

int main() {
    File file;
    char line[MAX_LINE_LENGTH];
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    open_file(&file, filename);
    while (read_line(line, file.file) > 0) {
        printf("%s", line);
    }
    close_file(&file);
    return 0;
}