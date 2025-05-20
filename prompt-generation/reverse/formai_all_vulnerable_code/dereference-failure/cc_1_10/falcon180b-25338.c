//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to calculate the checksum of a buffer
unsigned int calculate_checksum(char *buffer, int buffer_size) {
    unsigned int checksum = 0;
    for (int i = 0; i < buffer_size; i++) {
        checksum += buffer[i];
    }
    return checksum;
}

int main() {
    // Open the input file
    FILE *input_file = fopen("input.txt", "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        return 1;
    }

    // Get the size of the input file
    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    rewind(input_file);

    // Read the input file into a buffer
    char *buffer = (char *) malloc(file_size + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory for buffer.\n");
        fclose(input_file);
        return 1;
    }
    fread(buffer, file_size, 1, input_file);
    buffer[file_size] = '\0';

    // Calculate the checksum
    unsigned int checksum = calculate_checksum(buffer, file_size);

    // Print the checksum
    printf("Checksum: %08X\n", checksum);

    // Free the buffer and close the input file
    free(buffer);
    fclose(input_file);

    return 0;
}