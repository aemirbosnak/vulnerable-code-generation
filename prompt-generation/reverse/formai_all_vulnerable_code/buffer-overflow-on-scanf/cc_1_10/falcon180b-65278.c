//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 64

int main() {
    char key[KEY_SIZE];
    char input_file[256];
    char output_file[256];
    char buffer[BLOCK_SIZE];
    FILE *input_fp, *output_fp;

    // Get input file name
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Get output file name
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Get encryption key
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Open input file
    input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open output file
    output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file in blocks
    while (fread(buffer, 1, BLOCK_SIZE, input_fp) > 0) {
        // Encrypt block
        for (int i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] = buffer[i] ^ key[i % KEY_SIZE];
        }

        // Write encrypted block to output file
        fwrite(buffer, 1, BLOCK_SIZE, output_fp);
    }

    // Close input and output files
    fclose(input_fp);
    fclose(output_fp);

    printf("File encryption successful!\n");
    return 0;
}