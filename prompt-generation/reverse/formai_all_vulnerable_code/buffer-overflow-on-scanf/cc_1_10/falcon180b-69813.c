//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to calculate checksum using the CRC-32 algorithm
unsigned int calculate_checksum(char* data, int length) {
    unsigned int crc = 0xffffffff;
    for (int i = 0; i < length; i++) {
        crc ^= data[i];
        for (int j = 0; j < 8; j++) {
            crc = crc & 1? (crc >> 1) ^ 0xedb88320 : crc >> 1;
        }
    }
    return ~crc;
}

int main() {
    char input_file[MAX_LENGTH];
    char output_file[MAX_LENGTH];

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input file for reading
    FILE* input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Get file size
    fseek(input_fp, 0, SEEK_END);
    int file_size = ftell(input_fp);
    fseek(input_fp, 0, SEEK_SET);

    // Allocate memory to hold file contents
    char* file_contents = (char*) malloc(file_size);
    if (file_contents == NULL) {
        printf("Error: Could not allocate memory.\n");
        fclose(input_fp);
        return 1;
    }

    // Read file contents into memory
    int bytes_read = fread(file_contents, 1, file_size, input_fp);
    if (bytes_read!= file_size) {
        printf("Error: Could not read entire file.\n");
        free(file_contents);
        fclose(input_fp);
        return 1;
    }
    fclose(input_fp);

    // Calculate checksum
    unsigned int checksum = calculate_checksum(file_contents, file_size);

    // Write checksum to output file
    FILE* output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        printf("Error: Could not open output file.\n");
        free(file_contents);
        return 1;
    }
    fwrite(&checksum, 1, sizeof(unsigned int), output_fp);
    fclose(output_fp);

    // Print checksum to console
    printf("Checksum: %08X\n", checksum);

    // Free memory
    free(file_contents);

    return 0;
}