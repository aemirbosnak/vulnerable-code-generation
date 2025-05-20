//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

// Function to compare two files and synchronize them
void synchronize_files(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_SIZE], line2[MAX_LINE_SIZE];
    int line_num = 0;

    // Read the first line from both files
    fgets(line1, MAX_LINE_SIZE, file1);
    fgets(line2, MAX_LINE_SIZE, file2);

    // Compare the lines and write the changes to file1
    while (line1[0]!= '\0' || line2[0]!= '\0') {
        int result = strcmp(line1, line2);

        if (result == 0) {
            // Lines are identical, move to next line
            fgets(line1, MAX_LINE_SIZE, file1);
            fgets(line2, MAX_LINE_SIZE, file2);
        } else if (result < 0) {
            // Line in file1 is different, write changes to file1
            fprintf(file1, "Line %d: %s\n", line_num + 1, line2);
            fgets(line1, MAX_LINE_SIZE, file1);
        } else {
            // Line in file2 is different, write changes to file2
            fprintf(file2, "Line %d: %s\n", line_num + 1, line1);
            fgets(line2, MAX_LINE_SIZE, file2);
        }

        line_num++;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s file1 file2 output\n", argv[0]);
        return 1;
    }

    // Open the input files
    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    // Open the output file
    FILE *output = fopen(argv[3], "w");

    if (output == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    // Synchronize the files and write changes to the output file
    synchronize_files(file1, file2);

    // Close all files
    fclose(file1);
    fclose(file2);
    fclose(output);

    return 0;
}