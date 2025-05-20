//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
} FileContext;

void read_file_into_memory(FileContext *context) {
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    while (fgets(line, MAX_LINE_LENGTH, context->file)!= NULL) {
        line_number++;
        printf("Line %d: %s", line_number, line);
    }
}

int main() {
    FileContext file1, file2;
    char filename1[100], filename2[100];
    printf("Enter the name of the first file: ");
    scanf("%s", filename1);
    printf("Enter the name of the second file: ");
    scanf("%s", filename2);

    file1.filename = filename1;
    file1.file = fopen(filename1, "r");
    if (file1.file == NULL) {
        printf("Error: could not open file %s\n", filename1);
        exit(1);
    }

    file2.filename = filename2;
    file2.file = fopen(filename2, "r");
    if (file2.file == NULL) {
        printf("Error: could not open file %s\n", filename2);
        exit(1);
    }

    int line_number = 0;
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    while (fgets(line1, MAX_LINE_LENGTH, file1.file)!= NULL) {
        line_number++;
        printf("Line %d of file 1: %s", line_number, line1);
        if (fgets(line2, MAX_LINE_LENGTH, file2.file) == NULL) {
            printf("Line %d of file 2 is missing!\n", line_number);
        } else {
            printf("Line %d of file 2: %s", line_number, line2);
        }
    }

    if (fgets(line2, MAX_LINE_LENGTH, file2.file)!= NULL) {
        printf("Line %d of file 2 is extra!\n", line_number);
    }

    fclose(file1.file);
    fclose(file2.file);
    return 0;
}