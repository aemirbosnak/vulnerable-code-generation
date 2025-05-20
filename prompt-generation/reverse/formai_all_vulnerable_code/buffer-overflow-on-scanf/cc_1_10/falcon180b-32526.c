//Falcon-180B DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILENAME_LENGTH 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    FILE *file;
} File;

void open_file(File *file, const char *filename) {
    if (file->filename[0] == '\0') {
        strcpy(file->filename, filename);
    }
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    if (file->file!= NULL) {
        fclose(file->file);
        file->file = NULL;
    }
}

void read_file(File *file, char *buffer) {
    if (file->file == NULL) {
        printf("Error: file not open\n");
        exit(1);
    }
    fgets(buffer, MAX_LINE_LENGTH, file->file);
}

void write_file(File *file, const char *buffer) {
    if (file->file == NULL) {
        printf("Error: file not open\n");
        exit(1);
    }
    fprintf(file->file, "%s", buffer);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    File file;
    open_file(&file, filename);

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file.file)!= NULL) {
        printf("%s", buffer);
    }

    close_file(&file);

    return 0;
}