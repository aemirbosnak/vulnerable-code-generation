//Falcon-180B DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char *filename;
    FILE *file;
    char line[MAX_LINE_LENGTH];
} File;

int open_file(File *file, char *filename) {
    if ((file->file = fopen(filename, "r")) == NULL) {
        printf("Error opening file '%s'!\n", filename);
        exit(1);
    }
    return 0;
}

int close_file(File *file) {
    if (fclose(file->file)!= 0) {
        printf("Error closing file!\n");
        exit(1);
    }
    return 0;
}

int read_line(File *file) {
    if (fgets(file->line, MAX_LINE_LENGTH, file->file) == NULL) {
        printf("Error reading line!\n");
        exit(1);
    }
    return 0;
}

int print_line(File *file) {
    printf("%s", file->line);
    return 0;
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    File file;
    open_file(&file, filename);

    while (read_line(&file) == 0) {
        print_line(&file);
    }

    close_file(&file);

    return 0;
}