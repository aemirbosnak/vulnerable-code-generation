//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: Linus Torvalds
// File Encryptor in Linus Torvalds style
// This program uses a simple XOR cipher to encrypt and decrypt files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key and the size of the cipher
#define KEY 0xAB
#define SIZE 1024

// Function to encrypt a file
void encrypt_file(char *input_file, char *output_file) {
    // Open the input and output files
    FILE *infile = fopen(input_file, "rb");
    FILE *outfile = fopen(output_file, "wb");

    // Read the input file and encrypt it using the XOR cipher
    char buffer[SIZE];
    while (fread(buffer, SIZE, 1, infile) > 0) {
        for (int i = 0; i < SIZE; i++) {
            buffer[i] ^= KEY;
        }
        fwrite(buffer, SIZE, 1, outfile);
    }

    // Close the files
    fclose(infile);
    fclose(outfile);
}

// Function to decrypt a file
void decrypt_file(char *input_file, char *output_file) {
    // Open the input and output files
    FILE *infile = fopen(input_file, "rb");
    FILE *outfile = fopen(output_file, "wb");

    // Read the input file and decrypt it using the XOR cipher
    char buffer[SIZE];
    while (fread(buffer, SIZE, 1, infile) > 0) {
        for (int i = 0; i < SIZE; i++) {
            buffer[i] ^= KEY;
        }
        fwrite(buffer, SIZE, 1, outfile);
    }

    // Close the files
    fclose(infile);
    fclose(outfile);
}

// Main function to demonstrate the use of the encrypt and decrypt functions
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input file> <output file> <mode>\n", argv[0]);
        printf("Mode should be either 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    // Get the input and output file names and mode from the command line
    char *input_file = argv[1];
    char *output_file = argv[2];
    char *mode = argv[3];

    // Check if the mode is valid
    if (strcmp(mode, "encrypt") != 0 && strcmp(mode, "decrypt") != 0) {
        printf("Invalid mode. Must be either 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    // Call the appropriate function based on the mode
    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else {
        decrypt_file(input_file, output_file);
    }

    return 0;
}