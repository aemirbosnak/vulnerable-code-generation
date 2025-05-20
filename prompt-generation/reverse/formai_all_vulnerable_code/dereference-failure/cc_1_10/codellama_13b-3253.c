//Code Llama-13B DATASET v1.0 Category: Data recovery tool ; Style: beginner-friendly
/*
 * A beginner-friendly C data recovery tool example program
 *
 * This program reads a file and prints the data in hexadecimal format.
 * It also allows the user to write the data back to a file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file for reading
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Create a buffer to store the file data
    char buffer[1024];
    int size;

    // Read the file data into the buffer
    size = fread(buffer, 1, sizeof(buffer), file);
    if (ferror(file)) {
        printf("Error reading file: %s\n", argv[1]);
        fclose(file);
        return 1;
    }

    // Print the file data in hexadecimal format
    for (int i = 0; i < size; i++) {
        printf("%02x ", buffer[i]);
    }
    printf("\n");

    // Write the file data back to a file
    char output_filename[256];
    strcpy(output_filename, argv[1]);
    strcat(output_filename, ".out");

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Error opening output file: %s\n", output_filename);
        fclose(file);
        return 1;
    }

    size = fwrite(buffer, 1, size, output_file);
    if (ferror(output_file)) {
        printf("Error writing to output file: %s\n", output_filename);
        fclose(file);
        fclose(output_file);
        return 1;
    }

    printf("File data written to %s\n", output_filename);

    // Clean up
    fclose(file);
    fclose(output_file);

    return 0;
}