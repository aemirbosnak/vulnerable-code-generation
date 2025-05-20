//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Error: Incorrect number of arguments.\n");
        return 1;
    }

    // Open the input file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Get the size of the input file
    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    rewind(input_file);

    // Allocate memory for the input buffer
    char *input_buffer = malloc(file_size + 1);
    if (input_buffer == NULL) {
        printf("Error: Could not allocate memory for input buffer.\n");
        return 1;
    }

    // Read the input file into the input buffer
    size_t bytes_read = fread(input_buffer, 1, file_size, input_file);
    if (bytes_read!= file_size) {
        printf("Error: Could not read entire input file.\n");
        return 1;
    }
    input_buffer[file_size] = '\0';

    // Close the input file
    fclose(input_file);

    // Calculate the checksum
    unsigned int checksum = 0;
    for (int i = 0; i < file_size; i++) {
        checksum += input_buffer[i];
    }

    // Open the output file
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    // Write the checksum to the output file
    fprintf(output_file, "%08X", checksum);

    // Close the output file
    fclose(output_file);

    // Free the memory allocated for the input buffer
    free(input_buffer);

    return 0;
}