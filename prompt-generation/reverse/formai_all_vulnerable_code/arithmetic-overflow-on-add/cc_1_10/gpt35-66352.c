//FormAI DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define ENCRYPTION_OFFSET 10

int main(int argc, char *argv[]) {
    // Check if enough arguments were supplied
    if (argc < 2) {
        printf("Error: Please provide a filename to encrypt\n");
        return 1;
    }

    // Get filename from arguments
    char filename[MAX_FILENAME_LENGTH];
    strcpy(filename, argv[1]);

    // Open file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    // Get file size
    fseek(file, 0L, SEEK_END);
    int filesize = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // Allocate memory for file contents
    char *contents = (char*) malloc(filesize + 1);

    // Read file contents into memory
    fread(contents, sizeof(char), filesize, file);
    fclose(file);

    // Encrypt file contents
    for (int i = 0; i < filesize; i++) {
        contents[i] += ENCRYPTION_OFFSET;
    }

    // Write encrypted contents to file
    char output_filename[MAX_FILENAME_LENGTH];
    sprintf(output_filename, "%s_encrypted", filename);
    FILE *output_file = fopen(output_filename, "w");
    fwrite(contents, sizeof(char), filesize, output_file);
    fclose(output_file);

    printf("File successfully encrypted!\n");

    return 0;
}