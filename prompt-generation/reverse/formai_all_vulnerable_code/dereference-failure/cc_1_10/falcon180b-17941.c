//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to synchronize files
void synchronize_files(char *file1, char *file2) {
    FILE *fp1, *fp2;
    char line1[MAX_LINE_SIZE], line2[MAX_LINE_SIZE];
    int line_count = 0;

    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file(s)!\n");
        exit(1);
    }

    // Read the first file and compare with the second file
    while (fgets(line1, MAX_LINE_SIZE, fp1)!= NULL) {
        line_count++;
        if (fgets(line2, MAX_LINE_SIZE, fp2) == NULL) {
            // File 1 has more lines than file 2
            printf("File 1 has %d more lines.\n", line_count);
            break;
        } else if (strcmp(line1, line2)!= 0) {
            // Files are not synchronized
            printf("Files are not synchronized!\n");
            exit(1);
        }
    }

    // If file 2 has more lines than file 1
    if (fgets(line2, MAX_LINE_SIZE, fp2)!= NULL) {
        printf("File 2 has %d more lines.\n", line_count);
    }

    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }

    synchronize_files(argv[1], argv[2]);

    return 0;
}