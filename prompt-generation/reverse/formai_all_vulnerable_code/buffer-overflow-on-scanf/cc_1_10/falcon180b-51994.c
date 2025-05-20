//Falcon-180B DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_FILE_NAME 20

typedef struct {
    char name[MAX_FILE_NAME];
    FILE *file;
} File;

void open_file(File *file, char *filename) {
    strcpy(file->name, filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
}

void close_file(File *file) {
    fclose(file->file);
}

void read_file(File *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file->file)!= NULL) {
        printf("%s", line);
    }
}

int main() {
    File file1, file2;
    char filename1[MAX_FILE_NAME];
    char filename2[MAX_FILE_NAME];

    printf("Enter the name of the first file: ");
    scanf("%s", filename1);
    open_file(&file1, filename1);

    printf("Enter the name of the second file: ");
    scanf("%s", filename2);
    open_file(&file2, filename2);

    printf("Enter the name of the output file: ");
    scanf("%s", filename1);
    FILE *output_file = fopen(filename1, "w");

    if (output_file == NULL) {
        printf("Error: Could not create output file %s\n", filename1);
        exit(1);
    }

    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];

    while (fgets(line1, MAX_LINE_LENGTH, file1.file)!= NULL &&
           fgets(line2, MAX_LINE_LENGTH, file2.file)!= NULL) {
        if (strcmp(line1, line2) == 0) {
            fprintf(output_file, "%s", line1);
        }
    }

    fclose(output_file);

    close_file(&file1);
    close_file(&file2);

    return 0;
}