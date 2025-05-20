//Falcon-180B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    FILE *file;
} File;

void init_file(File *file, char *filename) {
    strcpy(file->filename, filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    fclose(file->file);
}

int read_line(File *file, char *buffer) {
    int length = 0;
    char c;
    while ((c = fgetc(file->file))!= EOF) {
        if (length >= MAX_LINE_LENGTH) {
            printf("Error: Line too long\n");
            exit(1);
        }
        buffer[length++] = c;
    }
    buffer[length] = '\0';
    return length;
}

int main() {
    File file;
    char line[MAX_LINE_LENGTH];
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    init_file(&file, filename);
    while (read_line(&file, line) > 0) {
        printf("%s", line);
    }
    close_file(&file);
    return 0;
}