//Falcon-180B DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
} File;

void open_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->file = fopen(filename, "r");

    if (file->file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    fclose(file->file);
    free(file->filename);
}

char *read_line(File *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file->file) == NULL) {
        return NULL;
    }
    return line;
}

int main() {
    File file;
    char *line;

    printf("Enter filename: ");
    scanf("%s", file.filename);

    open_file(&file, file.filename);

    while ((line = read_line(&file))!= NULL) {
        printf("%s", line);
    }

    close_file(&file);

    return 0;
}