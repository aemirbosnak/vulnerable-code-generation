//Falcon-180B DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    FILE *fp;
    char line[MAX_LINE_LENGTH];
} File;

void init_file(File *file, const char *filename) {
    file->filename = strdup(filename);
    file->fp = fopen(filename, "r");
    if (!file->fp) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    if (file->fp) {
        fclose(file->fp);
        file->fp = NULL;
    }
    free(file->filename);
}

int read_line(File *file) {
    char *ptr = fgets(file->line, MAX_LINE_LENGTH, file->fp);
    if (!ptr) {
        if (ferror(file->fp)) {
            printf("Error reading file: %s\n", file->filename);
        }
        return 0;
    }
    return 1;
}

int main() {
    File file;
    char input[MAX_LINE_LENGTH];
    int count = 0;

    printf("Enter filename: ");
    scanf("%s", input);

    init_file(&file, input);

    while (read_line(&file)) {
        printf("%d: %s", ++count, file.line);
    }

    close_file(&file);

    return 0;
}