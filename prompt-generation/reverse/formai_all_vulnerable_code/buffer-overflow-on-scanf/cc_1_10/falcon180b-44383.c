//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    FILE *file;
    char filename[MAX_FILE_NAME_LENGTH];
} File;

int open_file(File *f, const char *filename) {
    f->filename[0] = '\0';
    strncat(f->filename, filename, MAX_FILE_NAME_LENGTH - 1);
    f->file = fopen(f->filename, "r");
    if (f->file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    return 0;
}

int read_line(File *f, char *buffer) {
    if (fgets(buffer, MAX_LINE_LENGTH, f->file) == NULL) {
        printf("Error reading line from file\n");
        exit(1);
    }
    return 0;
}

int close_file(File *f) {
    fclose(f->file);
    f->filename[0] = '\0';
    return 0;
}

int main() {
    File file;
    char filename[MAX_FILE_NAME_LENGTH];
    char buffer[MAX_LINE_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    open_file(&file, filename);

    while (read_line(&file, buffer) == 0) {
        printf("%s", buffer);
    }

    close_file(&file);

    return 0;
}