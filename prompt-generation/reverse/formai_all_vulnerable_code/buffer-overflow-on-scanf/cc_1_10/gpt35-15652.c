//FormAI DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // Max length of file name

int main() {

    char filename[MAX_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);

    // Check file extension
    char ext[5];
    strncpy(ext, filename + (strlen(filename) - 4), 5);

    if (strcmp(ext, ".txt") != 0) {
        printf("Invalid file format. Only .txt files are supported.\n");
        return -1;
    }

    FILE *fp; // File pointer
    fp = fopen(filename, "r");

    if (!fp) {
        printf("Error opening file.\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_END); // Move to end of file
    long int file_size = ftell(fp); // Get file size in bytes
    rewind(fp); // Move to beginning of file

    char *file_buffer; // Allocate buffer for the entire file
    file_buffer = (char *) malloc(file_size * sizeof(char));

    if (!file_buffer) {
        printf("Error allocating memory.\n");
        return -1;
    }

    fread(file_buffer, sizeof(char), file_size, fp); // Read file into buffer

    printf("%s", file_buffer); // Print file contents

    fclose(fp);
    free(file_buffer); // Free memory

    return 0;
}