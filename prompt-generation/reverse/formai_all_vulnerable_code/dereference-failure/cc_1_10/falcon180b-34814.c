//Falcon-180B DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_NAME_SIZE 50

typedef struct {
    char *filename;
    FILE *file;
} FileStruct;

void createFile(char *filename) {
    FileStruct *file = malloc(sizeof(FileStruct));
    file->filename = strdup(filename);
    file->file = fopen(file->filename, "w");
    if (file->file == NULL) {
        fprintf(stderr, "Error: Could not create file %s\n", filename);
        exit(1);
    }
}

void writeLine(FileStruct *file, char *line) {
    fprintf(file->file, "%s", line);
    fprintf(file->file, "\n");
}

void closeFile(FileStruct *file) {
    fclose(file->file);
    free(file->filename);
    free(file);
}

int main() {
    char input[MAX_LINE_SIZE];
    char filename[MAX_FILE_NAME_SIZE];
    char line[MAX_LINE_SIZE];
    int lineNumber = 1;
    FileStruct *file;

    printf("Enter filename: ");
    fgets(filename, MAX_FILE_NAME_SIZE, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    createFile(filename);

    while (fgets(input, MAX_LINE_SIZE, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0';
        strcpy(line, input);
        writeLine(file, line);
        lineNumber++;
    }

    closeFile(file);

    printf("Wrote %d lines to file %s\n", lineNumber, filename);

    return 0;
}