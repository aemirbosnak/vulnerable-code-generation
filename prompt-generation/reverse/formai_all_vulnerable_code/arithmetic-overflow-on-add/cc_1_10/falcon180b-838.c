//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int line_number;
} File;

void open_files(File *file1, File *file2) {
    printf("Enter the name of the first file: ");
    scanf("%s", file1->name);
    file1->file = fopen(file1->name, "r");

    if (file1->file == NULL) {
        printf("Error: could not open file %s\n", file1->name);
        exit(1);
    }

    printf("Enter the name of the second file: ");
    scanf("%s", file2->name);
    file2->file = fopen(file2->name, "r");

    if (file2->file == NULL) {
        printf("Error: could not open file %s\n", file2->name);
        exit(1);
    }
}

void read_files(File *file1, File *file2) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file1->file)!= NULL) {
        file1->line_number++;
        strcpy(file1->line, line);
    }

    while (fgets(line, MAX_LINE_LENGTH, file2->file)!= NULL) {
        file2->line_number++;
        strcpy(file2->line, line);
    }
}

void close_files(File *file1, File *file2) {
    fclose(file1->file);
    fclose(file2->file);
}

void synchronize_files(File *file1, File *file2) {
    int i, j;

    i = 0;
    j = 0;

    while (i < file1->line_number && j < file2->line_number) {
        if (strcmp(file1->line, file2->line) == 0) {
            i++;
            j++;
        } else if (strcmp(file1->line, file2->line) < 0) {
            i++;
        } else {
            j++;
        }
    }

    printf("Synchronization complete.\n");
}

int main() {
    File file1, file2;

    open_files(&file1, &file2);
    read_files(&file1, &file2);
    synchronize_files(&file1, &file2);
    close_files(&file1, &file2);

    return 0;
}