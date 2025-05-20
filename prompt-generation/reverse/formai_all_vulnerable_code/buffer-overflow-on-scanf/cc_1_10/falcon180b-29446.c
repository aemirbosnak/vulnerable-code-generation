//Falcon-180B DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    FILE *file;
} File;

void open_file(File *file, char *filename) {
    strcpy(file->filename, filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
        file->file = NULL;
    }
}

char *read_line(File *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        printf("Error: Could not allocate memory for line\n");
        exit(1);
    }
    fgets(line, MAX_LINE_LENGTH, file->file);
    line[strcspn(line, "\n")] = '\0';
    return line;
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    File file;
    open_file(&file, filename);

    char *line;
    while ((line = read_line(&file))!= NULL) {
        printf("%s", line);
    }

    close_file(&file);

    return 0;
}