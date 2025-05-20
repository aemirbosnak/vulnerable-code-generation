//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_LINE_LEN 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    FILE *file;
} File;

void init_file(File *file, const char *file_name) {
    strcpy(file->file_name, file_name);
    file->file = fopen(file_name, "r");
    if (file->file == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }
}

void close_file(File *file) {
    fclose(file->file);
}

void read_line(File *file, char *line) {
    fgets(line, MAX_LINE_LEN, file->file);
    line[strcspn(line, "\n")] = '\0';  // Remove newline character
}

int main() {
    File file1, file2;
    char line1[MAX_LINE_LEN], line2[MAX_LINE_LEN];
    int line_num = 0;

    printf("Enter the name of the first file: ");
    scanf("%s", file1.file_name);
    init_file(&file1, file1.file_name);

    printf("Enter the name of the second file: ");
    scanf("%s", file2.file_name);
    init_file(&file2, file2.file_name);

    while (fgets(line1, MAX_LINE_LEN, file1.file)!= NULL &&
           fgets(line2, MAX_LINE_LEN, file2.file)!= NULL) {
        line_num++;
        if (strcmp(line1, line2)!= 0) {
            printf("Difference found in line %d:\n", line_num);
            printf("File 1: %s\n", line1);
            printf("File 2: %s\n", line2);
            printf("\n");
        }
    }

    close_file(&file1);
    close_file(&file2);

    return 0;
}