//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

// Function to compare two files and synchronize them
void synchronize_files(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    int line_num1 = 0, line_num2 = 0;

    // Read the first line from both files
    fgets(line1, MAX_LINE_LENGTH, file1);
    fgets(line2, MAX_LINE_LENGTH, file2);

    while (line1[0]!= '\0' && line2[0]!= '\0') {
        // Compare the lines
        int result = strcmp(line1, line2);

        // If the lines are different, write the changes to file2
        if (result!= 0) {
            fprintf(file2, "%d,%d,%s\n", line_num1, line_num2, line1);
            fputc(line2[0], file2);
            while (line2[0]!= '\n' && line2[0]!= '\0') {
                line2[0] = fgetc(file2);
            }
        }

        // Read the next line from both files
        fgets(line1, MAX_LINE_LENGTH, file1);
        fgets(line2, MAX_LINE_LENGTH, file2);

        // Increment line numbers
        line_num1++;
        line_num2++;
    }

    // Handle any remaining lines in file1
    while (line1[0]!= '\0') {
        fprintf(file2, "%d,%d,%s\n", line_num1, line_num2, line1);
        fputc(line1[0], file2);
        while (line1[0]!= '\n' && line1[0]!= '\0') {
            line1[0] = fgetc(file1);
        }
        line_num1++;
    }

    // Handle any remaining lines in file2
    while (line2[0]!= '\0') {
        fputc(line2[0], file1);
        while (line2[0]!= '\n' && line2[0]!= '\0') {
            line2[0] = fgetc(file2);
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r+");
    FILE *file2 = fopen(argv[2], "r+");

    if (file1 == NULL || file2 == NULL) {
        fprintf(stderr, "Error opening file(s)\n");
        return 1;
    }

    synchronize_files(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}