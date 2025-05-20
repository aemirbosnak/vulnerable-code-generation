//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1000

/**
 * Calculates the checksum of a given buffer using the CRC-32 algorithm.
 *
 * @param buffer The buffer to calculate the checksum of.
 * @param length The length of the buffer.
 *
 * @return The calculated checksum.
 */
unsigned int calculate_checksum(const unsigned char* buffer, int length) {
    unsigned int crc = 0xffffffff;
    for (int i = 0; i < length; i++) {
        crc ^= buffer[i];
        for (int j = 0; j < 8; j++) {
            crc = (crc >> 1) ^ (0xedb88320 & -(crc & 1));
        }
    }
    return crc ^ 0xffffffff;
}

int main() {
    char input_file_path[MAX_BUFFER_SIZE];
    char output_file_path[MAX_BUFFER_SIZE];
    char buffer[MAX_BUFFER_SIZE];
    unsigned int checksum;

    // Get the input file path from the user
    printf("Enter the input file path: ");
    scanf("%s", input_file_path);

    // Open the input file for reading
    FILE* input_file = fopen(input_file_path, "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Read the contents of the input file into a buffer
    fseek(input_file, 0, SEEK_END);
    int input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    fread(buffer, input_file_size, 1, input_file);
    fclose(input_file);

    // Calculate the checksum of the buffer
    checksum = calculate_checksum(buffer, input_file_size);

    // Get the output file path from the user
    printf("Enter the output file path: ");
    scanf("%s", output_file_path);

    // Open the output file for writing
    FILE* output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    // Write the checksum to the output file
    fwrite(&checksum, sizeof(unsigned int), 1, output_file);
    fclose(output_file);

    printf("Checksum calculated and saved to %s.\n", output_file_path);

    return 0;
}