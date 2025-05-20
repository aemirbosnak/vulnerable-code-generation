//Code Llama-13B DATASET v1.0 Category: File handling ; Style: all-encompassing
/*
* Example C File Handling Program
*
* This program demonstrates how to read and write to a file in C.
*
* To compile and run:
* 1. Save this code to a file with a .c extension (e.g. file_handling.c)
* 2. Compile the code using a C compiler (e.g. gcc file_handling.c -o file_handling)
* 3. Run the program using ./file_handling
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    FILE *file;
    char *buffer;
    char *file_name = "test.txt";
    size_t buffer_size = 1024;
    size_t bytes_read;
    size_t bytes_written;

    // Open file for reading
    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        return 1;
    }

    // Allocate memory for buffer
    buffer = (char *)malloc(buffer_size * sizeof(char));
    if (buffer == NULL) {
        printf("Error allocating memory for buffer\n");
        return 1;
    }

    // Read from file
    bytes_read = fread(buffer, sizeof(char), buffer_size, file);
    printf("Read %ld bytes from file\n", bytes_read);

    // Write to file
    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        return 1;
    }
    bytes_written = fwrite(buffer, sizeof(char), bytes_read, file);
    printf("Wrote %ld bytes to file\n", bytes_written);

    // Close file
    fclose(file);

    // Free memory
    free(buffer);

    return 0;
}