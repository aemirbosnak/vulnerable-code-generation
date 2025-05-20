//FormAI DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the given file
void encrypt(char *input_file, char *output_file, char *key) {
    FILE *in_file, *out_file;
    unsigned char byte, xor_key;
    size_t i = 0, key_len = strlen(key);

    // Open input and output files
    in_file = fopen(input_file, "rb");
    out_file = fopen(output_file, "wb");

    // Encrypt each byte using the key
    while (fread(&byte, sizeof(unsigned char), 1, in_file) == 1) {
        // Get the corresponding byte from the XOR key
        xor_key = key[i % key_len];
        i++;

        // XOR the byte with the key
        byte = byte ^ xor_key;

        // Write the encrypted byte to the output file
        fwrite(&byte, sizeof(unsigned char), 1, out_file);
    }

    // Close the files
    fclose(in_file);
    fclose(out_file);
}

// Main function
int main() {
    char input_file[100], output_file[100], key[100];

    // Get input file name
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", input_file);

    // Get output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // Get encryption key
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Encrypt the file
    encrypt(input_file, output_file, key);

    // Display success message
    printf("File encrypted successfully!\n");

    return 0;
}