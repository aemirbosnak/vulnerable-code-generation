//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

int main() {
    char first_file[MAX_FILENAME_LENGTH], second_file[MAX_FILENAME_LENGTH];
    FILE *fp1, *fp2;
    int ch1, ch2;
    int is_synced = 1; // flag to detect if files are syncronized

    // Get input from user
    printf("Enter name of first file: ");
    scanf("%s", first_file);
    printf("Enter name of second file: ");
    scanf("%s", second_file);

    // Open files
    fp1 = fopen(first_file, "r");
    fp2 = fopen(second_file, "r");

    // Compare files
    while (1) {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        // If both files reached EOF, they match
        if (ch1 == EOF && ch2 == EOF) {
            break;
        }

        // If only one file reached EOF, they don't match
        if (ch1 == EOF || ch2 == EOF) {
            is_synced = 0;
            break;
        }

        // If characters don't match, files don't match
        if (ch1 != ch2) {
            is_synced = 0;
            break;
        }
    }

    // Close files
    fclose(fp1);
    fclose(fp2);

    // Print result
    if (is_synced) {
        printf("Files are synchronized.\n");
    } else {
        printf("Files are not synchronized.\n");
    }

    return 0;
}