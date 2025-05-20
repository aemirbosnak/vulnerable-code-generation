//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    FILE* file;
} File;

File* open_file(char* filename) {
    File* file = malloc(sizeof(File));
    strcpy(file->name, filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    return file;
}

char* read_line(File* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, file->file);
    return line;
}

void close_file(File* file) {
    fclose(file->file);
    free(file);
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    File* file = open_file(filename);

    char* line;
    while ((line = read_line(file))!= NULL) {
        printf("%s", line);
    }

    close_file(file);

    return 0;
}