//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1024 // Maximum file size in bytes

// Function to compare two files and return the difference
int compareFiles(char *file1, char *file2, FILE *fp1, FILE *fp2) {
    int c1, c2, diff = 0;
    char line1[MAX_FILE_SIZE], line2[MAX_FILE_SIZE];

    while ((c1 = fgetc(fp1))!= EOF || (c2 = fgetc(fp2))!= EOF) {
        if (c1!= c2) {
            printf("Difference found at line %d:\n", diff + 1);
            printf("File 1: %s\n", line1);
            printf("File 2: %s\n", line2);
            return 1;
        }

        if (c1 == '\n') {
            strcpy(line1, "");
            diff++;
        } else {
            strncat(line1, &c1, 1);
        }

        if (c2 == '\n') {
            strcpy(line2, "");
            diff++;
        } else {
            strncat(line2, &c2, 1);
        }
    }

    if (c1!= c2) {
        printf("Difference found at line %d:\n", diff + 1);
        printf("File 1: %s\n", line1);
        printf("File 2: %s\n", line2);
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    char *file1 = argv[1];
    char *file2 = argv[2];
    FILE *fp1, *fp2;

    fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        printf("Error opening file %s\n", file1);
        return 1;
    }

    fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        printf("Error opening file %s\n", file2);
        return 1;
    }

    int diff = compareFiles(file1, file2, fp1, fp2);

    fclose(fp1);
    fclose(fp2);

    return diff;
}