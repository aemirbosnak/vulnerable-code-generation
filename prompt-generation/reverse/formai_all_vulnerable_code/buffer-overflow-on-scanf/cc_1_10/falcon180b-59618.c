//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_LENGTH 100

void synchronize_files(char *file1, char *file2) {
    FILE *fp1, *fp2;
    char line1[MAX_FILE_LENGTH], line2[MAX_FILE_LENGTH];
    int line_count = 0;

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file(s).\n");
        exit(1);
    }

    while (fgets(line1, MAX_FILE_LENGTH, fp1)!= NULL && fgets(line2, MAX_FILE_LENGTH, fp2)!= NULL) {
        line_count++;
        if (strcmp(line1, line2)!= 0) {
            printf("Difference found in line %d:\n", line_count);
            printf("File 1: %s\n", line1);
            printf("File 2: %s\n", line2);
        }
    }

    if (ferror(fp1)!= 0 || ferror(fp2)!= 0) {
        printf("Error reading file(s).\n");
        exit(1);
    }

    fclose(fp1);
    fclose(fp2);

    if (line_count == 0) {
        printf("Files are empty or identical.\n");
    } else {
        printf("Files synchronized successfully.\n");
    }
}

int main() {
    char file1[100], file2[100];

    printf("Enter the name of the first file: ");
    scanf("%s", file1);
    printf("Enter the name of the second file: ");
    scanf("%s", file2);

    synchronize_files(file1, file2);

    return 0;
}