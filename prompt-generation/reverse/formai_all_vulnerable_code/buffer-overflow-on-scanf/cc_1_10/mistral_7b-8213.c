//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define FILENAME_SIZE 256

int main(void) {
    FILE *src_file = NULL;
    FILE *dest_file = NULL;
    char buffer[MAX_BUFFER_SIZE];
    char src_filename[FILENAME_SIZE];
    char dest_filename[FILENAME_SIZE];
    size_t read_bytes;

    // Check user input for valid filenames
    printf("Enter source file name: ");
    scanf("%s", src_filename);
    printf("Enter destination file name: ");
    scanf("%s", dest_filename);

    // Open source file
    src_file = fopen(src_filename, "rb");
    if (src_file == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Open destination file
    dest_file = fopen(dest_filename, "wb");
    if (dest_file == NULL) {
        perror("Error opening destination file");
        fclose(src_file);
        exit(EXIT_FAILURE);
    }

    // Read data from source file
    while ((read_bytes = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, src_file)) > 0) {
        // Write data to destination file
        if (fwrite(buffer, sizeof(char), read_bytes, dest_file) != read_bytes) {
            perror("Error writing to destination file");
            fclose(src_file);
            fclose(dest_file);
            exit(EXIT_FAILURE);
        }
    }

    // Check for errors during file reading or writing
    if (ferror(src_file) != 0 || ferror(dest_file) != 0) {
        perror("Error during file read/write");
        fclose(src_file);
        fclose(dest_file);
        exit(EXIT_FAILURE);
    }

    // Close source and destination files
    fclose(src_file);
    fclose(dest_file);

    printf("Data copied successfully!\n");

    return EXIT_SUCCESS;
}