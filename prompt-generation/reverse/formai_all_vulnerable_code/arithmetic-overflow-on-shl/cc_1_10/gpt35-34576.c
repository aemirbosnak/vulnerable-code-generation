//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int compute_checksum(char *buffer, int buffer_size) {
    // Define local variables
    int i, j, checksum = 0;

    // Compute the checksum using Shannon's algorithm
    for (i = 0; i < buffer_size; i++) {
        checksum ^= buffer[i];
        for (j = 0; j < 8; j++) {
            if (checksum & 0x80) {
                checksum = (checksum << 1) ^ 0x07;
            } else {
                checksum <<= 1;
            }
        }
    }

    // Return the final checksum value
    return checksum;
}

int main(int argc, char **argv) {
    // Define local variables
    FILE *fp;
    char buffer[BUFFER_SIZE];
    int buffer_size, checksum_value;

    // Check if filename is provided as input
    if (argc < 2) {
        printf("Please specify the input filename\n");
        return EXIT_FAILURE;
    }

    // Open the input file in read mode
    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Unable to open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Read the contents of the file into a buffer
    buffer_size = fread(buffer, sizeof(char), BUFFER_SIZE, fp);
    fclose(fp);

    // Compute the checksum value
    checksum_value = compute_checksum(buffer, buffer_size);

    // Print the results to the console
    printf("Checksum value for %s: %d\n", argv[1], checksum_value);

    return EXIT_SUCCESS;
}