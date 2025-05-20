//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];
    FILE *input_fp, *output_fp;
    char buffer[MAX_SIZE];
    unsigned long checksum = 0;
    int bytes_read;

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input file
    input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Open output file
    output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_fp);
        exit(1);
    }

    // Calculate checksum
    while ((bytes_read = fread(buffer, 1, MAX_SIZE, input_fp)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            checksum += (unsigned char)buffer[i];
        }
    }

    // Write checksum to output file
    fprintf(output_fp, "Checksum: %lu\n", checksum);

    // Close input and output files
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}