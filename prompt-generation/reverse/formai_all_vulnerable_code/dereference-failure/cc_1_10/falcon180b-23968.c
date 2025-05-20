//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes

// Function to compare two files and synchronize them
void synchronize_files(FILE *file1, FILE *file2) {
    char line1[MAX_FILE_SIZE], line2[MAX_FILE_SIZE];
    int line_num1 = 0, line_num2 = 0;

    // Read first file line by line
    while (fgets(line1, MAX_FILE_SIZE, file1)!= NULL) {
        line_num1++;

        // Read second file line by line until we find the same line
        while (fgets(line2, MAX_FILE_SIZE, file2)!= NULL && strcmp(line1, line2)!= 0) {
            line_num2++;
        }

        // If we reached the end of second file, append the rest of first file
        if (feof(file2)) {
            rewind(file2);
            while (fgets(line2, MAX_FILE_SIZE, file2)!= NULL) {
                fprintf(stdout, "Appending line %d from file1: %s\n", line_num1, line1);
                fprintf(file2, "%s", line1);
                line_num1++;
            }
            break;
        }

        // If we found the same line, write it to output file
        fprintf(stdout, "Synchronizing line %d: %s\n", line_num1, line1);
        fprintf(file2, "%s", line1);
        line_num2++;
    }

    // If second file has extra lines, delete them
    while (fgets(line2, MAX_FILE_SIZE, file2)!= NULL) {
        fprintf(stdout, "Deleting line %d from file2: %s\n", line_num2, line2);
        line_num2++;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    synchronize_files(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}