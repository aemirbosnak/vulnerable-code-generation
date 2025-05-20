//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void synchronize(FILE *file1, FILE *file2) {
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    int bytes_read1, bytes_read2;
    int line_count = 0;

    // Read first file and write to buffer
    while ((bytes_read1 = fread(buffer1, sizeof(char), BUFFER_SIZE, file1)) > 0) {
        buffer1[bytes_read1 - 1] = '\0';
        printf("%s", buffer1);
        line_count++;
    }

    // Read second file and compare to first file
    while ((bytes_read2 = fread(buffer2, sizeof(char), BUFFER_SIZE, file2)) > 0) {
        buffer2[bytes_read2 - 1] = '\0';
        if (strcmp(buffer1, buffer2)!= 0) {
            printf("Difference found at line %d:\n", line_count);
            printf("File 1:\n%s\n", buffer1);
            printf("File 2:\n%s\n", buffer2);
        }
        line_count++;
    }
}

int main() {
    FILE *file1, *file2;
    char filename1[50], filename2[50];

    // Get filenames from user
    printf("Enter the name of the first file: ");
    scanf("%s", filename1);
    printf("Enter the name of the second file: ");
    scanf("%s", filename2);

    // Open files in read mode
    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");

    // Check if files were opened successfully
    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    // Synchronize files
    synchronize(file1, file2);

    // Close files
    fclose(file1);
    fclose(file2);

    return 0;
}