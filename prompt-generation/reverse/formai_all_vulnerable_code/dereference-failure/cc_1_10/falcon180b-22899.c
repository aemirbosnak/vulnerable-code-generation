//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to synchronize files
void synchronize_files(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    int line_num = 1;

    // Read first file
    while (fgets(line1, MAX_LINE_LENGTH, file1)) {
        // Reset second file pointer to beginning
        rewind(file2);

        // Read second file
        while (fgets(line2, MAX_LINE_LENGTH, file2)) {
            // Compare lines from both files
            if (strcmp(line1, line2)!= 0) {
                // If lines are different, print line numbers and differences
                printf("Line %d: %s\n", line_num, line1);
                printf("Line %d: %s\n", line_num, line2);
            }

            // Increment line number
            line_num++;

            // Reset second file pointer to beginning for next comparison
            rewind(file2);
        }
    }
}

int main() {
    FILE *file1, *file2;
    char filename1[MAX_LINE_LENGTH], filename2[MAX_LINE_LENGTH];

    // Get file names from user
    printf("Enter first file name: ");
    scanf("%s", filename1);
    printf("Enter second file name: ");
    scanf("%s", filename2);

    // Open files
    file1 = fopen(filename1, "r");
    if (file1 == NULL) {
        printf("Error: Could not open file %s.\n", filename1);
        exit(1);
    }

    file2 = fopen(filename2, "r");
    if (file2 == NULL) {
        printf("Error: Could not open file %s.\n", filename2);
        exit(1);
    }

    // Synchronize files
    synchronize_files(file1, file2);

    // Close files
    fclose(file1);
    fclose(file2);

    return 0;
}