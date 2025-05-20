//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

// Function to compare two strings (case insensitive)
int strcasecmp(const char *s1, const char *s2) {
    char c1, c2;
    while ((c1 = tolower(*s1)) && (c2 = tolower(*s2))) {
        if (c1!= c2)
            return c1 - c2;
        s1++;
        s2++;
    }
    return 0;
}

// Function to synchronize two files
void synchronize_files(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    char filename1[MAX_FILE_NAME_LENGTH], filename2[MAX_FILE_NAME_LENGTH];

    // Read the first line from both files
    fgets(line1, MAX_LINE_LENGTH, file1);
    fgets(line2, MAX_LINE_LENGTH, file2);

    // Compare the first lines
    int result = strcasecmp(line1, line2);

    if (result == 0) {
        // The files are already synchronized
        printf("Files are already synchronized.\n");
        return;
    } else if (result < 0) {
        // File 1 is ahead of file 2
        printf("File 1 is ahead of file 2.\n");
        rewind(file1);
        while (fgets(line1, MAX_LINE_LENGTH, file1)!= NULL) {
            fputs(line1, file2);
        }
    } else {
        // File 2 is ahead of file 1
        printf("File 2 is ahead of file 1.\n");
        rewind(file2);
        while (fgets(line2, MAX_LINE_LENGTH, file2)!= NULL) {
            fputs(line2, file1);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    // Open the files for reading and writing
    FILE *file1 = fopen(argv[1], "r+");
    FILE *file2 = fopen(argv[2], "r+");

    if (file1 == NULL || file2 == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    // Synchronize the files
    synchronize_files(file1, file2);

    // Close the files
    fclose(file1);
    fclose(file2);

    return 0;
}