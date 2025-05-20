//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to compare two files
int compare_files(FILE *file1, FILE *file2) {
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    int bytes_read1, bytes_read2;

    // Read first file into buffer
    bytes_read1 = fread(buffer1, sizeof(char), BUFFER_SIZE, file1);
    if (bytes_read1 == 0) {
        printf("End of file reached in first file.\n");
        return 0;
    }

    // Read second file into buffer
    bytes_read2 = fread(buffer2, sizeof(char), BUFFER_SIZE, file2);
    if (bytes_read2 == 0) {
        printf("End of file reached in second file.\n");
        return 0;
    }

    // Compare buffers
    while (bytes_read1 > 0 && bytes_read2 > 0) {
        if (strcmp(buffer1, buffer2)!= 0) {
            printf("Files are not synchronized.\n");
            return 1;
        }
        bytes_read1 = fread(buffer1, sizeof(char), BUFFER_SIZE, file1);
        bytes_read2 = fread(buffer2, sizeof(char), BUFFER_SIZE, file2);
    }

    // Check for end of file in either file
    if (bytes_read1 == 0) {
        printf("End of file reached in first file.\n");
        return 0;
    } else if (bytes_read2 == 0) {
        printf("End of file reached in second file.\n");
        return 0;
    }

    // Files are synchronized
    printf("Files are synchronized.\n");
    return 0;
}

// Function to synchronize two files
void synchronize_files(FILE *file1, FILE *file2) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Read first file into buffer
    bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file1);
    while (bytes_read > 0) {
        // Write buffer to second file
        fwrite(buffer, sizeof(char), bytes_read, file2);

        // Read next buffer from first file
        bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file1);
    }
}

int main() {
    FILE *file1, *file2;
    char file_name1[100], file_name2[100];

    // Get file names from user
    printf("Enter name of first file: ");
    scanf("%s", file_name1);
    printf("Enter name of second file: ");
    scanf("%s", file_name2);

    // Open files
    file1 = fopen(file_name1, "r");
    if (file1 == NULL) {
        printf("Error opening first file.\n");
        exit(1);
    }
    file2 = fopen(file_name2, "w");
    if (file2 == NULL) {
        printf("Error opening second file.\n");
        exit(1);
    }

    // Synchronize files
    compare_files(file1, file2);
    synchronize_files(file1, file2);

    // Close files
    fclose(file1);
    fclose(file2);

    return 0;
}