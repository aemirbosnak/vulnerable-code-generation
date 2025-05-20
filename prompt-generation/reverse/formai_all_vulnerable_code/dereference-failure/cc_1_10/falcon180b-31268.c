//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_SIZE);
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF && ch!= '\n') {
        line[i++] = ch;
    }

    line[i] = '\0';
    return line;
}

// Function to compare two files and synchronize them
void synchronize_files(FILE* file1, FILE* file2) {
    char* line1 = NULL;
    char* line2 = NULL;
    int line_count = 0;

    // Read the first line from both files
    line1 = read_line(file1);
    line2 = read_line(file2);

    // Compare the two lines and print the differences
    while (line1!= NULL || line2!= NULL) {
        if (line1 == NULL && line2!= NULL) {
            // Line is missing in file1
            printf("Line %d is missing in file1\n", line_count);
            line1 = read_line(file1);
        } else if (line2 == NULL && line1!= NULL) {
            // Line is missing in file2
            printf("Line %d is missing in file2\n", line_count);
            line2 = read_line(file2);
        } else if (strcmp(line1, line2)!= 0) {
            // Lines are different
            printf("Line %d is different\n", line_count);
            printf("File1: %s\n", line1);
            printf("File2: %s\n", line2);
        } else {
            // Lines are the same
            printf("Line %d is the same\n", line_count);
        }

        line_count++;

        // Read the next line from both files
        free(line1);
        line1 = read_line(file1);
        free(line2);
        line2 = read_line(file2);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    FILE* file1 = fopen(argv[1], "r");
    FILE* file2 = fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    synchronize_files(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}