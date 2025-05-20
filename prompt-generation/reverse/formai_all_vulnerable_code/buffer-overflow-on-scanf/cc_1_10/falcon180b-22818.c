//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16 // Length of the encryption key
#define BLOCK_SIZE 8 // Number of bytes in a block

void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    unsigned char key_bytes[KEY_LENGTH]; // Key in bytes
    int i, j;

    // Convert key to bytes
    for (i = 0; i < KEY_LENGTH; i++) {
        key_bytes[i] = (unsigned char) key[i];
    }

    unsigned char buffer[BLOCK_SIZE]; // Buffer for reading/writing blocks
    int bytes_read, bytes_written;

    // Read input file in blocks
    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, input_file)) > 0) {
        // Encrypt block
        for (i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] ^= key_bytes[i % KEY_LENGTH];
        }

        // Write encrypted block to output file
        bytes_written = fwrite(buffer, 1, BLOCK_SIZE, output_file);
        if (bytes_written!= BLOCK_SIZE) {
            printf("Error writing to output file.\n");
            exit(1);
        }
    }
}

int main() {
    char input_file_name[100];
    char output_file_name[100];
    char key[KEY_LENGTH];

    // Get input file name
    printf("Enter input file name: ");
    scanf("%s", input_file_name);

    // Get output file name
    printf("Enter output file name: ");
    scanf("%s", output_file_name);

    // Get encryption key
    printf("Enter encryption key (up to %d characters): ", KEY_LENGTH);
    scanf("%s", key);

    // Open input file
    FILE *input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open output file
    FILE *output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Encrypt file
    encrypt_file(input_file, output_file, key);

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}